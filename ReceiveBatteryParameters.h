#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SendBatteryParameters.h"
void batteryParametersReceiver(BatteryChargingParameters *batteryParameters);
void ReadDataFromConsole(BatteryChargingParameters *batteryParameters);
BatteryChargingParameters ComputeMinBMSParameter(BatteryChargingParameters *batteryParameters);
BatteryChargingParameters ComputeMaxBMSParameter(BatteryChargingParameters *batteryParameters);
BatteryChargingParameters ComputeAvgBMSParameter(BatteryChargingParameters *batteryParameters);
