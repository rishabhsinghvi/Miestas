#ifndef FRAME_ALLOCATOR_H
#define FRAME_ALLOCATOR_H

#include "MemoryAllocator.h"

namespace Miestas
{
	class FrameAllocator : public MemoryAllocator
	{
	private:
		void* m_Arena;
		void* m_Cur;
		size_t m_ArenaSize;
		size_t m_Used;

	public:

		FrameAllocator() = default;

		FrameAllocator(size_t arenaSizeBytes);

		~FrameAllocator();

		virtual void* Allocate(size_t bytes, size_t alignment) override;

		virtual void Free(void* ptr) override;

		void Reset();

	};
}

#endif