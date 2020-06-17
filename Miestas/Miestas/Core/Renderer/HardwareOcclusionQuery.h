#ifndef HARDWARE_OCCLUSION_QUERY_H
#define HARDWARE_OCCLUSION_QUERY_H

#include "HardwareQuery.h"

namespace Miestas
{
	struct HardwareOcclusionQuery : public HardwareQuery
	{
		virtual void BeginQuery() = 0;

		virtual void EndQuery() = 0;

		virtual void GetQueryResult(uint32_t& samplesPassed) = 0;
	};
}

#endif