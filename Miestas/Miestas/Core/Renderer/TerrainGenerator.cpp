#include "TerrainGenerator.h"
#include "Logger/Logger.h"

#include "Utils/FastNoise.h"

#include "json/json.hpp"

#include<fstream>
#include<random>

#include <glm/glm.hpp>

constexpr int RANDOM_MIN = 1;
constexpr int RANDOM_MAX = 10000000;

namespace Miestas
{
	namespace Renderer
	{
		struct Vertex
		{
			float x, y, z;
			
			Vertex() = default;
		};

		void TerrainGenerator::init(const std::string& configFilePath)
		{
			using json = nlohmann::json;

			std::fstream configFile(configFilePath);

			if (!configFile)
			{
				MIESTAS_FAILURE("Unable to open Terrain Config File: {0}", configFilePath)
			}

			json root;
			configFile >> root;

			m_terrainSize = root["TERRAIN_SIZE"];

			m_terrainScaleFactor = root["TERRAIN_SCALE_FACTOR"];
			m_terrainHeightScaleFactor = root["TERRAIN_HEIGHT_AMPLITUDE"];
			

			bool isRandomTerrain = root["TERRAIN_GEN_RANDOM"];


			if (!isRandomTerrain)
			{
				m_randomSeed = root["TERRAIN_GEN_SEED"];
			}
			else
			{
				std::random_device device;
				std::mt19937 randomgen(device());

				std::uniform_int_distribution<std::mt19937::result_type> dist(RANDOM_MIN, RANDOM_MAX);

				m_randomSeed = dist(randomgen);

				root["TERRAIN_GEN_RANDOM"] = false;
				root["TERRAIN_GEN_SEED"] = m_randomSeed;

				configFile << root;
			}

			m_isInitialized = true;

			MIESTAS_LOG_INFO("TerrainGenerator: Initialized successfully.")

			generateTerrain();

		}

		void TerrainGenerator::generateTerrain()
		{
			if (!m_isInitialized)
				return;

			FastNoise noiseGenerator;
			noiseGenerator.SetNoiseType(FastNoise::Perlin);
			noiseGenerator.SetSeed(m_randomSeed);

			// Generate vertices
			std::vector<Vertex> vertices;

			for (auto z = 0; z <= m_terrainSize; z++)
			{
				for (auto x = 0; x <= m_terrainSize; x++)
				{
					float vX = static_cast<float>(x) * m_terrainScaleFactor;
					float vZ = static_cast<float>(z) * m_terrainScaleFactor;
					float vY = noiseGenerator.GetNoise(vX, vZ) * m_terrainHeightScaleFactor;

					vertices.push_back({ vX, vY, vZ });
				}
			}

			// Generate indices
			for (auto z = 0; z < m_terrainSize; z++)
			{
				for (auto x = 0; x < m_terrainSize; x++)
				{
					auto r1 = z * (m_terrainSize + 1);
					auto r2 = (z + 1) * (m_terrainSize + 1);

					m_terrainIndexData.push_back(r1 + x);
					m_terrainIndexData.push_back(r1 + x + 1);
					m_terrainIndexData.push_back(r2 + x + 1);

					m_terrainIndexData.push_back(r1 + x);
					m_terrainIndexData.push_back(r2 + x + 1);
					m_terrainIndexData.push_back(r2 + x);
				}
			}

			//Finally, generate vertex data (position, normal, color)

			// Each Vertex contains 3 floats and we need 3 times that amount
			// Bit inefficient to recalculate normals for already calculated vertices (too much space)
			// Might reconsider it later
			m_terrainVertexData.resize(vertices.size() * 3 * 3); 

			for (auto i = 0; i < m_terrainIndexData.size(); i += 3)
			{
				glm::vec3 v1(vertices[m_terrainIndexData[i]].x, vertices[m_terrainIndexData[i]].y, vertices[m_terrainIndexData[i]].z);
				glm::vec3 v2(vertices[m_terrainIndexData[i+1]].x, vertices[m_terrainIndexData[i+1]].y, vertices[m_terrainIndexData[i+1]].z);
				glm::vec3 v3(vertices[m_terrainIndexData[i+2]].x, vertices[m_terrainIndexData[i+2]].y, vertices[m_terrainIndexData[i+2]].z);

				glm::vec3 normal = glm::normalize(glm::cross(v1 - v2, v3 - v1));

				// First vertex
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 0] = v1.x;
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 1] = v1.y;
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 2] = v1.z;

				m_terrainVertexData[m_terrainIndexData[i] * 9 + 3] = normal.x;
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 4] = normal.y;
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 5] = normal.z;

				// Color it black for now
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 6] = 0.0f;
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 7] = 0.0f;
				m_terrainVertexData[m_terrainIndexData[i] * 9 + 8] = 0.0f;


				//Second vertex
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 0] = v2.x;
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 1] = v2.y;
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 2] = v2.z;

				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 3] = normal.x;
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 4] = normal.y;
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 5] = normal.z;

				// Color it black for now
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 6] = 0.0f;
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 7] = 0.0f;
				m_terrainVertexData[m_terrainIndexData[i+1] * 9 + 8] = 0.0f;



				//Third vertex
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 0] = v3.x;
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 1] = v3.y;
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 2] = v3.z;

				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 3] = normal.x;
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 4] = normal.y;
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 5] = normal.z;

				// Color it black for now
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 6] = 0.0f;
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 7] = 0.0f;
				m_terrainVertexData[m_terrainIndexData[i+2] * 9 + 8] = 0.0f;
			}

			


			// GENERATE TERRAIN

			MIESTAS_LOG_INFO("TerrainGenerator: Terrain generated successfully")
		}

		const std::vector<float>& TerrainGenerator::getTerrainVertices() const
		{
			return m_terrainVertexData;
		}

		const std::vector<unsigned int>& TerrainGenerator::getTerrainIndices() const
		{
			return m_terrainIndexData;
		}

	}
}