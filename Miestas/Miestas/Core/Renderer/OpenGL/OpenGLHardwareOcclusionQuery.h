#ifndef OPENGL_HARDWARE_OCCLUSION_QUERY_H
#define OPENGL_HARDWARE_OCCLUSION_QUERY_H

#include "Core/Renderer/RenderCommon.h"
#include "Core/Renderer/HardwareOcclusionQuery.h"

namespace Miestas
{
	class OpenGLHardwareOcclusionQuery : public HardwareOcclusionQuery
	{
	private:
		RenderID m_QID;
	
	public:

		OpenGLHardwareOcclusionQuery(); 

		virtual ~OpenGLHardwareOcclusionQuery();

		virtual void BeginQuery() override;

		virtual void EndQuery() override;

		virtual void GetQueryResult(uint32_t& samplesPassed) override;
		
	};
}

#endif