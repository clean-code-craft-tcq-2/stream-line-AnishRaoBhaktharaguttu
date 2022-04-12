#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char *buf = NULL;
    int size;
    size_t length;
    size = getline(&buf, &length, stdin);
    if (size != -1)
        /* do anything you want with the stuff that was entered here */
        /* for the example I just write it back to stdout! */
        puts(buf);
    else
        /* this would be your "end" condition */
        printf("Nothing read!\n");

    printf("Size: %d\n Length: %d\n", size, length);
    free(buf);
	
	
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
