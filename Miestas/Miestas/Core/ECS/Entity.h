#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

#include "ECSCommon.h"

namespace Miestas
{
	class Registry;

	class Entity
	{
	private:
		EntityHandle m_Handle;
		Registry* m_Registry;

	public:
		
		Entity() = default;

		EntityHandle GetHandle() const
		{
			return m_Handle;
		}

		Registry* GetRegistry() const
		{
			return m_Registry;
		}
	};
}

#endif