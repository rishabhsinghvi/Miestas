//#include "Font.h"
//#include "Logger/Logger.h"
//
//#include "ft2build.h"
//#include FT_FREETYPE_H
//
//namespace Miestas
//{
//	namespace Renderer
//	{
//		void Font::init()
//		{
//			FT_Library freetype;
//
//			if (FT_Init_FreeType(&freetype))
//			{
//				MIESTAS_FAILURE("FreeType Error: Could not initialize FreeType library.")
//			}
//
//			FT_Face face;
//			if (FT_New_Face(freetype, m_fontPath.c_str(), 0, &face))
//			{
//				MIESTAS_FAILURE("FreeType Error: Could not load font: {0}", m_fontPath)
//			}
//
//			FT_Set_Pixel_Sizes(face, 0, m_fontHeight);
//
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//			for (auto i = 0; i < 128; i++)
//			{
//				if (FT_Load_Char(face, i, FT_LOAD_RENDER))
//				{
//					MIESTAS_FAILURE("FreeType Error: Could not load glyph: {0}", static_cast<char>(i))
//				}
//
//				GLuint textureId;
//
//				glGenTextures(1, &textureId);
//				glBindTexture(GL_TEXTURE_2D, textureId);
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
//
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//				Character c = { textureId, glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
//					glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
//					face->glyph->advance.x
//				};
//
//				m_characterSet.insert({ i, c });
//			}
//		}
//	}
//}
//
