#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *batteryParameters)
{	
    char buffer[1000];
    int arr[STREAM_SIZE];
    int arr1[STREAM_SIZE];
    size_t line = 0;

    while ((fgets(buffer, sizeof buffer, stdin) != NULL)) {
        if (sscanf(buffer, "%.3f   %.3f", &arr[line],&arr1[line]) != 1) {
            fprintf(stderr, "Line formatting error\n");
            exit(EXIT_FAILURE);
        }
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
