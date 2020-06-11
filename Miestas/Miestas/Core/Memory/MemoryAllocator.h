#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

namespace Miestas
{
	struct MemoryAllocator
	{
		virtual void* Allocate(size_t bytes, size_t alignment) = 0;

		virtual void Free(void* ptr) = 0;
	};
}

#endif