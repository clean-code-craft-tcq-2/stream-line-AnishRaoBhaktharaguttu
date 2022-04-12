#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char buffer[100];
    while(fgets(buffer, sizeof buffer, stdin) != NULL) {
        if(sscanf(buffer, "%.3f", batteryParameters->temperature) != 1) {    // or strtol perhaps
            break;
        }
        printf("Number: %d\n", batteryParameters->temperature);
	batteryParameters++;
    }
  //for (int i = 0; i < STREAM_SIZE; i++)
	//{
	//	scanf("%f\t%f\n", batteryParameters->temperature, batteryParameters->stateOfCharge);
	//        batteryParameters++;
	//}
  
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
