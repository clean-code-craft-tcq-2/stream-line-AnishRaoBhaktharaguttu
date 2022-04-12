#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{
  for (int i = 0; i < STREAM_SIZE; i++)
	{
		scanf("%f\t%f\n", &batteryParameters[i].temperature, &batteryParameters[i].stateOfCharge);
	}
  
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
