#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include "ECSCommon.h"
#include "TypeId.h"

namespace Miestas
{
	struct BaseComponent
	{
		// EMPTY
	};

	template<typename T>
	struct Component : public BaseComponent
	{
		static ComponentHandle GetTypeId()
		{
			return TypeId<BaseComponent>::GetID<T>();
		}

	};
}

#endif