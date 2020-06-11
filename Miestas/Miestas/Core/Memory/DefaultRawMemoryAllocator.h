#ifndef DEFAULT_RAW_MEMORY_ALLOCATOR
#define DEFAULT_RAW_MEMORY_ALLOCATOR

#include "MemoryAllocator.h"

namespace Miestas
{
	class DefaultRawMemoryAllocator : public MemoryAllocator
	{
		DefaultRawMemoryAllocator() = default;

		virtual void* Allocate(size_t bytes, size_t alignment = 0) override;

		virtual void Free(void* ptr) override;
	};
}

#endif