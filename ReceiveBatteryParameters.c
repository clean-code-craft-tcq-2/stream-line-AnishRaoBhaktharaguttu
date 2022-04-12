#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char buffer[1000];
    int arr[50];
    size_t line = 0;
    printf("Temperature: 3.420 deg C , State of Charge: 11.060\n");
    while ((fgets(buffer, sizeof buffer, stdin) != NULL)) {
	    printf("Temperature: 3.420 deg C , State of Charge: 11.060\n");
        if (sscanf(buffer, "%.3f", &arr[line]) != 1) {
            fprintf(stderr, "Line formatting error\n");
            exit(EXIT_FAILURE);
        }
        ++line;
    }

    for (size_t i = 0; i < line; i++) {
        printf("%.2f\n", arr[i]);
    }
	
	
    //char buffer[100];
    //while(fgets(buffer, sizeof buffer, stdin) != NULL) {
        //if(sscanf(buffer, "%.3f", batteryParameters->temperature) != 1) {    // or strtol perhaps
           // break;
       // }
      //  printf("Number: %d\n", batteryParameters->temperature);
	//batteryParameters++;
  //  }
	
	
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
