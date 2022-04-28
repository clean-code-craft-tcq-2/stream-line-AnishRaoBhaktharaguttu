#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SendBatteryParameters.h"
void BMS_Receiver(BatteryChargingParameters *BMS_DataPtr);
void ReadDataFromConsole(BatteryChargingParameters *BMS_DataPtr);
BatteryChargingParameters ComputeMinBMS_Data(BatteryChargingParameters *BMS_DataPtr);
BatteryChargingParameters ComputeMaxBMS_Data(BatteryChargingParameters *BMS_DataPtr);
BatteryChargingParameters ComputeAvgBMS_Data(BatteryChargingParameters *BMS_DataPtr);
