
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "SendBatteryParameters.h"

void readBatteryParametersFromFile(BatteryChargingParameters *batteryParameters)
{
  float temperature, stateOfCharge;
    FILE * parametersFile = fopen("batteryParameters.txt","r");  
    if (parametersFile!=NULL) {
        for(int j=0;fscanf(parametersFile, "%f\t%f\n", &temperature,&stateOfCharge)!=EOF ;j++)
        {
            batteryParameters->temperature = temperature;
            batteryParameters->stateOfCharge = stateOfCharge;
            batteryParameters++;
        }
    }
    fclose(parametersFile);  
}
