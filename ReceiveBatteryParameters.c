#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char ReadString[400];
    for(int i = 0; i < STREAM_SIZE ; i++)
   {  
	//scanf("%50s", ReadString);
	if(scanf("%50s", ReadString) == EOF) 
        {
            break;
        }
        scanf("%.3f", batteryParameters->temperature);
        scanf("%50s", ReadString); //deg
        scanf("%50s", ReadString); //C
        scanf("%50s", ReadString); //,
        scanf("%50s", ReadString); // State
        scanf("%50s", ReadString); //of
        scanf("%50s", ReadString); //charge:
        scanf("%.3ff", batteryParameters->stateOfCharge);
	printf("%.3f \t %.3f\n",batteryParameters->temperature,batteryParameters->stateOfCharge);
	batteryParameters++;
   }
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
