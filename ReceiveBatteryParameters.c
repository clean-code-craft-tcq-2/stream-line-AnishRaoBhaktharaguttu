#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"
float Temp[50] = {};
float Soc[50] = {};
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
