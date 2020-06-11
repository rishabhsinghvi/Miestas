#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

/*
The TextureManager is responsible for the loading and unloading of textures.
The Renderer has no direct contact with Textures.
*/
#include<unordered_map>
#include<string>
#include<memory>
#include<optional>

#include "Texture.h"
#include "CubeMap.h"

#include <assimp/scene.h>

namespace Miestas
{
	namespace Renderer
	{
		class TextureManager
		{
		private:
			std::unordered_map<std::string, std::shared_ptr<Texture>> m_textureCache;
			std::unordered_map<std::string, std::shared_ptr<CubeMap>> m_cubeMapCache;

		public:

			~TextureManager() = default;

			void loadTexture(const std::string& textureName, const std::string& texturePath, aiTextureType textureType);

			void loadTexture(const std::string& textureName, const std::vector<std::string>& texturePaths);

			std::shared_ptr<Texture> getTexture(const std::string& textureName);

		};
	}
}

#endif