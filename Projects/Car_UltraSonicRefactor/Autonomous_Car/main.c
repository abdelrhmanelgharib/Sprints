
#include "APP.h"

int main()
{

	APP_Init();

	while (1)
	{
		Sensor_mainFunction();

		MOTOR_mainFunction();
	}
}
