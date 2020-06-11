#ifndef BASE_BUFFER_OBJECT_H
#define BASE_BUFFER_OBJECT_H

#include<string>
#include<cstdint>

namespace Miestas
{
	enum BufferType
	{
		BT_VertexBuffer,
		BT_IndexBuffer,
		BT_UniformBuffer
	};

	enum BufferUsage
	{
		BU_Default,
		BU_Static,
		BU_Dynamic
	};

	struct BufferDescriptor
	{
		/// Name of Buffer for debugging
		std::string Name;

		/// Size of the buffer object in bytes
		uint32_t Size;

		/// Type of buffer object. See BufferType enum.
		BufferType Type;

		/// Usage of the buffer object. See BufferUsage enum.
		BufferUsage Usage;

	};


	class BaseBufferObject
	{
		
	};
}

#endif