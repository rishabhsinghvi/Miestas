#ifndef CHARACTER_H
#define CHARACTER_H

#include "glad/glad.h"

#include "glm/vec2.hpp"


namespace Miestas
{
	namespace Renderer
	{
		struct Character
		{
			GLuint m_textureId; // not using Texture class because this requires parameters not supported by it
			glm::ivec2 m_glyphSize;
			glm::ivec2 m_glyphBearing;
			GLuint m_Advance;
		};
	}
}

#endif