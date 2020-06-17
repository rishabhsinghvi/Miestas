#include "RenderContext.h"
#include "DeviceParameters.h"
#include "OpenGL/OpenGLRenderContext.h"
#include "Logger/Logger.h"

namespace Miestas
{
	std::unique_ptr<RenderContext> RenderContext::CreateRenderContext(RenderAPI renderAPI)
	{
		switch (renderAPI)
		{
		case RenderAPI::OpenGL:
		case RenderAPI::Default:
			return std::make_unique<OpenGLRenderContext>();
		
		case RenderAPI::Vulkan:
		default:
			MIESTAS_ASSERT(false, "Only OpenGL for now!");
		}
	}
	const DeviceParameters& RenderContext::DeviceParameters() const
	{
		return m_DeviceParameters;
	}
}