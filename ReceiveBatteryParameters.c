#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char buffer[1000];
    size_t line = 0;

    while ((fgets(buffer, sizeof buffer, stdin) != NULL)) {
        if (sscanf(buffer, "%.3f   %.3f", batteryParameters->temperature,batteryParameters->stateOfCharge) != 1) {
            fprintf(stderr, "Line formatting error\n");
            exit(EXIT_FAILURE);
        }
        batteryParameters++;
        ++line;
    }

    for (size_t i = 0; i < line; i++) {
        printf("%5d\n", arr[i]);
    }
}

void batteryParametersReceiver(BatteryChargingParameters *batteryParameters)
{
    ReadDataFromConsole(batteryParameters);
}
