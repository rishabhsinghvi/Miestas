#ifndef ECS_TYPEID_H
#define ECS_TYPEID_H

#include "ECSCommon.h"

namespace Miestas
{
	template<typename T>
	struct TypeId
	{
		static ECSId m_ID;
		
		template<typename U>
		static ECSId GetID()
		{
			const static ECSId ID = m_ID++;
			return ID;
		}
	};

	template<typename T>
	ECSId TypeId<T>::m_ID = 0;
}


#endif