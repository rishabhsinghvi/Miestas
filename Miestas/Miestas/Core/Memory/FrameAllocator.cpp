#include "FrameAllocator.h"
#include "MemUtils.h"
#include "Logger/Logger.h"


#include <cstdlib>

namespace Miestas
{
	FrameAllocator::FrameAllocator(size_t arenaSizeBytes):
		m_Arena(std::malloc(arenaSizeBytes)), m_ArenaSize(arenaSizeBytes)
	{
		if (!arenaSizeBytes)
		{
			MIESTAS_FAILURE("Unable to allocate enough memory.")
		}
	}

	FrameAllocator::~FrameAllocator()
	{
		if (m_Used > 0)
			MIESTAS_LOG_WARN("Deallocating memory still in use!")

		if (m_Arena)
			std::free(m_Arena);
		
	}

	void* FrameAllocator::Allocate(size_t bytes, size_t alignment)
	{
		auto alignedAddr = GetAlignedAddress(m_Cur, alignment);

		if (HasEnoughMemory(m_Arena, m_ArenaSize, alignedAddr, bytes))
		{
			m_Cur = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(alignedAddr) + bytes);
			m_Used += bytes;
			return alignedAddr;
		}

		else
		{
			MIESTAS_FAILURE("Unable to allocate enough memory!")
		}
	}

	void FrameAllocator::Free(void* ptr)
	{
		// NOTHING
	}


	void FrameAllocator::Reset()
	{
		m_Cur = m_Arena;
	}


}