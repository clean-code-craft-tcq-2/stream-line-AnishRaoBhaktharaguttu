
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
      batteryParameters->temperature = temperature;
      batteryParameters->stateOfCharge = stateOfCharge;
      batteryParameters++;
    }
    fclose(parametersFile);  
}

void sendBatteryParametersToConsole(BatteryChargingParameters *batteryParameters)
{
    for(int i = 0; i<STREAM_SIZE ;i++)
    {
     printf(" Temperature: %.3f deg C , State of Charge: %.3f",  batteryParameters->temperature, batteryParameters->stateOfCharge);
    }
}

void batteryParametersSender(BatteryChargingParameters *batteryParameters)
{
  readBatteryParametersFromFile(batteryParameters);
  sendBatteryParametersToConsole(batteryParameters);
}
