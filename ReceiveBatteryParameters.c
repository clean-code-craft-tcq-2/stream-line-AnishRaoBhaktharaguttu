#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"
float Temp[BMS_DATA] = {};
float Soc[BMS_DATA] = {};
void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
        for (int i = 0; i < 50; i++)
	{
		scanf("%f\t%f\n", &Temp[i], &Soc[i]);
	}
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
