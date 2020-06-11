#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include<memory>

namespace Miestas
{
	enum class RenderAPI
	{
		Default = 0,
		OpenGL = 1,
		Vulkan
	};

	class BaseBufferObject;
	struct BufferDescriptor;

	class RenderContext
	{
		static std::unique_ptr<RenderContext> CreateRenderContext(RenderAPI renderAPI);

		std::unique_ptr<BaseBufferObject> CreateBuffer(const BufferDescriptor& bufferDesc);

	};
}

#endif