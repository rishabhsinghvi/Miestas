#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include "DeviceParameters.h"

#include<memory>

namespace Miestas
{
	enum class RenderAPI
	{
		Default = 0,
		OpenGL = 1,
		Vulkan
	};

	/// Forward declarations
	class BaseBufferObject;
	struct BufferDescriptor;
	
	class BaseShaderObject;
	struct ShaderDescriptor;

	class RenderContext
	{
	protected:
		DeviceParameters m_DeviceParameters;

	public:
		static std::unique_ptr<RenderContext> CreateRenderContext(RenderAPI renderAPI);

		virtual std::unique_ptr<BaseBufferObject> CreateBuffer(const BufferDescriptor& bufferDesc) = 0;

		virtual std::unique_ptr<BaseShaderObject> CreateShader(const ShaderDescriptor& shaderDesc) = 0;

		virtual void QueryDeviceParameters() = 0;

		const DeviceParameters& DeviceParameters() const;
	};
}

#endif