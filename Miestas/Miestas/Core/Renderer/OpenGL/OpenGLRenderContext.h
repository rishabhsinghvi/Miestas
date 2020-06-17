#ifndef OPENGL_RENDER_CONTEXT_H
#define OPENGL_RENDER_CONTEXT_H

#include "Core/Renderer/RenderContext.h"



namespace Miestas
{
	class OpenGLRenderContext : public RenderContext
	{
		virtual std::unique_ptr<BaseBufferObject> CreateBuffer(const BufferDescriptor& bufferDesc) override;

		virtual std::unique_ptr<BaseShaderObject> CreateShader(const ShaderDescriptor& shaderDesc) override;

		virtual void QueryDeviceParameters() override;
	};
}

#endif