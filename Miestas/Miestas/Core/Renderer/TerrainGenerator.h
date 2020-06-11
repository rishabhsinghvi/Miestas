#ifndef TERRAIN_GENERATOR_H
#define TERRAIN_GENERATOR_H

#include<vector>
#include<string>

namespace Miestas
{
	namespace Renderer
	{
		class TerrainGenerator
		{
		private:
			int m_randomSeed;
			
			unsigned int m_terrainSize;

			float m_terrainScaleFactor; // how much to scale X and Z coordinates by
			float m_terrainHeightScaleFactor;

			std::vector<float> m_terrainVertexData;
			std::vector<unsigned int> m_terrainIndexData;

			bool m_isInitialized = false;

		public:

			TerrainGenerator() = default;

			void init(const std::string& configFilePath);

			void generateTerrain();

			const std::vector<float>& getTerrainVertices() const;

			const std::vector<unsigned int>& getTerrainIndices() const;
		};
	}
}

#endif