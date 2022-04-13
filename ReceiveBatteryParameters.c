#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char ReadString[400];
    printf("HI 1\n");
    for(int i = 0; i < STREAM_SIZE ; i++)
    {  
	printf("HI 2\n");
        if(scanf("%50s", ReadString) == EOF)
	{
		printf("HI 3\n");
		break;
	}
	printf("HI 4\n");
	scanf("%50s", ReadString);
        scanf("%f", batteryParameters->temperature);
        scanf("%50s", ReadString); //deg
        scanf("%50s", ReadString); //C
        scanf("%50s", ReadString); //,
        scanf("%50s", ReadString); // State
        scanf("%50s", ReadString); //of
        scanf("%50s", ReadString); //charge:
        scanf("%f", batteryParameters->stateOfCharge);
	printf("HI: 5\n",batteryParameters->temperature,batteryParameters->stateOfCharge);
	batteryParameters++;
    }
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
