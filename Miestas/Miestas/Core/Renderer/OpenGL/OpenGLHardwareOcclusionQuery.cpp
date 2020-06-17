#include "OpenGLHardwareOcclusionQuery.h"

#include "glad/glad.h"

namespace Miestas
{
	OpenGLHardwareOcclusionQuery::OpenGLHardwareOcclusionQuery()
	{
		glGenQueries(1, (GLuint*)&m_QID);
	}
	
	OpenGLHardwareOcclusionQuery::~OpenGLHardwareOcclusionQuery()
	{
		glDeleteQueries(1, (GLuint*)&m_QID);
	}

	void OpenGLHardwareOcclusionQuery::BeginQuery()
	{
		glBeginQuery(GL_SAMPLES_PASSED, m_QID);
	}

	void OpenGLHardwareOcclusionQuery::EndQuery()
	{
		glEndQuery(GL_SAMPLES_PASSED);
	}

	void OpenGLHardwareOcclusionQuery::GetQueryResult(uint32_t& samplesPassed)
	{
		glGetQueryObjectuiv(m_QID, GL_QUERY_RESULT, &samplesPassed);
	}
}