#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include<string>
#include<unordered_map>
#include<memory>

#include "Renderer/Shader.h"

namespace Miestas
{
	namespace Renderer
	{
		class ShaderManager
		{
		private:
			std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaderCache;
		public:

			~ShaderManager() = default;

			void loadShader(const std::string& shaderName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

			void loadShader(const std::string& shaderName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::string& geometryShaderPath);

			std::shared_ptr<Shader> getShader(const std::string& shaderName);
		};
	}
}

#endif