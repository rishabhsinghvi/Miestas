#ifndef DEVICE_PARAMETERS_H
#define DEVICE_PARAMETERS_H

#include<cstdint>

namespace Miestas
{
	struct DeviceParameters
	{

		struct ExtensionSupport
		{
			bool BindlessTextures = false;
		};

		ExtensionSupport Extensions;
		uint8_t MaxTextureUnits;
		
	};
}

#endif