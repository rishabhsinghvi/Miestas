#include "OpenGLRenderContext.h"
#include "Core/Renderer/DeviceParameters.h"

#include "glad/glad.h"

namespace Miestas
{
	std::unique_ptr<BaseBufferObject> OpenGLRenderContext::CreateBuffer(const BufferDescriptor& bufferDesc)
	{
		return std::unique_ptr<BaseBufferObject>();
	}

	std::unique_ptr<BaseShaderObject> OpenGLRenderContext::CreateShader(const ShaderDescriptor& shaderDesc)
	{
		return std::unique_ptr<BaseShaderObject>();
	}

	void OpenGLRenderContext::QueryDeviceParameters()
	{
		/// Check for bindless textures
		m_DeviceParameters.Extensions.BindlessTextures = GLAD_GL_ARB_bindless_texture;

	}


}