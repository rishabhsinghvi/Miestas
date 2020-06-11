#include "DefaultRawMemoryAllocator.h"

#include<cstdlib>
#include<new>

namespace Miestas
{

	void* DefaultRawMemoryAllocator::Allocate(size_t bytes, size_t alignment)
	{
		auto ptr = std::malloc(bytes);
		if (ptr)
			return ptr;

		throw std::bad_alloc();
	}

	void DefaultRawMemoryAllocator::Free(void* ptr)
	{
		if (!ptr)
			return;

		std::free(ptr);
	}



}