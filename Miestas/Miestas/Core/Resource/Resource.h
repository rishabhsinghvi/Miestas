#ifndef RESOURCE_H
#define RESOURCE_H

#include<string>
#include<cstdint>

namespace Miestas
{
	class ResourceLoader;
	class Listener;

	enum ResourceState
	{
		QUEUED_ASYNC_LOAD,
		LOADED,
		QUEUED_UNLOAD,
		UNLOADED,
	};

	class Resource
	{
	protected:
		// Name of the resource
		std::string m_Name;

		// Amount of memory in use
		uint32_t m_Bytes;

		// State of the resource
		ResourceState m_State;

	public:

		virtual bool Load(ResourceLoader* resourceSource) = 0;

		// Some resources can be optionally unloaded from memory.
		// NOTE: The Resource is still in memory.
		// Only the resource data is removed.174521
		virtual bool Unload() = 0;



	};


}

#endif