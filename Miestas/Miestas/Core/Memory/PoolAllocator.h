#ifndef POOL_ALLOCATOR
#define POOL_ALLOCATOR

#include<cstdlib>
#include<new>
#include<utility>

namespace Miestas
{
	template<typename T>
	class PoolAllocator
	{
	private:
		struct InternalNode
		{
			InternalNode* next;
		};

		void* m_ArenaStart = nullptr;
		InternalNode* m_Head;
		
		// Accepts max estimate for number of objects from this pool.
		PoolAllocator(size_t maxObjects)
		{
			m_ArenaStart = std::malloc(sizeof(T) * maxObjects);
			m_Head = reinterpret_cast<InternalNode*>(m_ArenaStart);

			for (auto i = 0; i < maxObjects; i++)
			{
				auto node = reinterpret_cast<InternalNode*>(reinterpret_cast<uintptr_t>(m_Head) + sizeof(T));
				node->next = m_Head;
				m_Head = node;
			}
		}

		~PoolAllocator()
		{
			if(m_ArenaStart)
				std::free(m_ArenaStart);
		}

		template<typename ... Args>
		T* Allocate(Args&& ... args)
		{
			if (!m_Head)
				throw std::bad_alloc;

			auto node = reinterpret_cast<void*>(m_Head);
			m_Head = m_Head->next;
			
			auto obj = new(node) T(std::forward<Args>(args)...);
			return obj;
		}

		void Free(T* obj)
		{
			if (!obj)
				return;

			obj->~T();
			auto node = reinterpret_cast<InternalNode*>(obj);
			node->next = m_Head;
			m_Head = node;
		}

	};
}

#endif