#ifndef MEM_UTILS_H
#define MEM_UTILS_H

namespace Miestas
{
	void* GetAlignedAddress(void* curPtr, size_t alignment);

	bool HasEnoughMemory(void* starPtr, size_t arenaSize, void* curPtr, size_t bytesToAllocate);
}

#endif