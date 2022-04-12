#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "SendBatteryParameters.h"

void readBatteryParametersFromFile(BatteryChargingParameters *batteryParameters)
{
  float temperature, stateOfCharge;
    FILE * parametersFile = fopen("batteryParameters.txt","r");  
    for(int j=0;fscanf(parametersFile, "%f\t%f\n", &temperature,&stateOfCharge)!=EOF ;j++)
    {
      batteryParameters->temperature = floorf(temperature * 100) / 100;
      batteryParameters->stateOfCharge = floorf(stateOfCharge * 100) / 100;
      batteryParameters++;
    }
    fclose(parametersFile);  
}

void sendBatteryParametersToConsole(BatteryChargingParameters *batteryParameters)
{
    FILE *endPoint = stdout;
    char buffer[100];
    char *bufferptr = buffer
    for(int i = 0; i<STREAM_SIZE ;i++)
    {
     sprintf(bufferptr," Temperature: %.3f deg C , State of Charge: %.3f\n",  batteryParameters->temperature, batteryParameters->stateOfCharge);
     fprintf (endPoint,"%s\n", bufferptr);
     batteryParameters++;
    }
}

void batteryParametersSender(BatteryChargingParameters *batteryParameters)
{
  readBatteryParametersFromFile(batteryParameters);
  sendBatteryParametersToConsole(batteryParameters);
}
