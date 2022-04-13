#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char ReadString[400];
    for(int i = 0; i < STREAM_SIZE ; i++)
    {
        if(scanf("%50s", ignoreString) != EOF)
	{
        scanf("%f", batteryParameters->temperature);
        scanf("%50s", ignoreString); //deg
        scanf("%50s", ignoreString); //C
        scanf("%50s", ignoreString); //,
        scanf("%50s", ignoreString); // State
        scanf("%50s", ignoreString); //of
        scanf("%50s", ignoreString); //charge:
        scanf("%f", batteryParameters->stateOfCharge);
	printf("%.2f\t%.2f\n",batteryParameters->temperature,batteryParameters->stateOfCharge);
        }
	batteryParameters++;
    }
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
