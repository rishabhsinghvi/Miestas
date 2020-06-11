#include "ShaderManager.h"
#include "Logger/Logger.h"

#include<algorithm>

#define STRING_TO_LOWER(x) std::transform(x.##begin(), x.##end(), x.##begin(), [](unsigned char ch){ return std::tolower(ch); });

namespace Miestas
{
	namespace Renderer
	{
		void ShaderManager::loadShader(const std::string& shaderName, const std::string & vertexShaderPath, const std::string & fragmentShaderPath)
		{
			STRING_TO_LOWER(const_cast<std::string&>(shaderName))

			if (m_shaderCache.find(shaderName) != m_shaderCache.end())
			{
				MIESTAS_LOG_WARN("ShaderManager: The following shader is already loaded: {0}", shaderName);
				return;
			}

			auto shader = std::make_shared<Shader>(shaderName, vertexShaderPath, fragmentShaderPath);
			m_shaderCache.insert({ shaderName, shader });
		}

		void ShaderManager::loadShader(const std::string& shaderName, const std::string & vertexShaderPath, const std::string & fragmentShaderPath, const std::string & geometryShaderPath)
		{
			STRING_TO_LOWER(const_cast<std::string&>(shaderName))

			if (m_shaderCache.find(shaderName) != m_shaderCache.end())
			{
				MIESTAS_LOG_WARN("ShaderManager: The following shader is already loaded: {0}", shaderName);
				return;
			}

			auto shader = std::make_shared<Shader>(shaderName, vertexShaderPath, fragmentShaderPath, geometryShaderPath);
			m_shaderCache.insert({ shaderName, shader });
		}

		std::shared_ptr<Shader> ShaderManager::getShader(const std::string & shaderName)
		{

			STRING_TO_LOWER(const_cast<std::string&>(shaderName))

			auto shaderLocation = m_shaderCache.find(shaderName);
			if (shaderLocation == m_shaderCache.end())
			{
				MIESTAS_FAILURE("ShaderManager: The requested texture hasn't been loaded  yet: {0}", shaderName)
			}

			return shaderLocation->second;
		}
	}
}