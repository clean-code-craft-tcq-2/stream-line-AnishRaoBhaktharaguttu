#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ReceiveBatteryParameters.h"

void ReadDataFromConsole(BatteryChargingParameters *BMS_DataPtr)
{	
    char ReadString[400];
    for(int i = 0; i < STREAM_SIZE ; i++)
   {  
	if(scanf("%50s", ReadString) == EOF) 
        {
            break;
        }
        scanf("%f", &(BMS_DataPtr->temperature));
        scanf("%50s", ReadString); //deg
        scanf("%50s", ReadString); //C
        scanf("%50s", ReadString); //,
        scanf("%50s", ReadString); // State
        scanf("%50s", ReadString); //of
        scanf("%50s", ReadString); //charge:
        scanf("%f", &(BMS_DataPtr->stateOfCharge));
	BMS_DataPtr++;
   }
}

BatteryChargingParameters ComputeMinBMS_Data(BatteryChargingParameters *BMS_DataPtr)
{
    BatteryChargingParameters MinValues={BMS_DataPtr->temperature,BMS_DataPtr->stateOfCharge};
    for(int i = 0; i < STREAM_SIZE; i++){
        if(BMS_DataPtr->temperature < MinValues.temperature)
	{
            MinValues.temperature=BMS_DataPtr->temperature;
        }
	if(BMS_DataPtr->stateOfCharge < MinValues.stateOfCharge)
	{
            MinValues.stateOfCharge=BMS_DataPtr->stateOfCharge;
        }
	BMS_DataPtr++;    
    }
	return MinValues;
}

BatteryChargingParameters ComputeMaxBMS_Data(BatteryChargingParameters *BMS_DataPtr)
{
    BatteryChargingParameters MaxValues={BMS_DataPtr->temperature,BMS_DataPtr->stateOfCharge};
    for(int i = 0; i < STREAM_SIZE; i++){
        if(BMS_DataPtr->temperature > MaxValues.temperature)
	{
            MaxValues.temperature=BMS_DataPtr->temperature;
        }
	if(BMS_DataPtr->stateOfCharge > MaxValues.stateOfCharge)
	{
            MaxValues.stateOfCharge=BMS_DataPtr->stateOfCharge;
        }
	BMS_DataPtr++;    
    }
	return MaxValues;
}

BatteryChargingParameters ComputeAvgBMS_Data(BatteryChargingParameters *BMS_DataPtr)
{
    BatteryChargingParameters AvgValues={0};
    BatteryChargingParameters Sum={0};
    for(int i = 0; i < STREAM_SIZE; i++)
    {
        Sum.temperature= Sum.temperature + BMS_DataPtr->temperature;
	Sum.stateOfCharge= Sum.stateOfCharge + BMS_DataPtr->stateOfCharge;
	BMS_DataPtr++;    
    }
    AvgValues.temperature = Sum.temperature/ STREAM_SIZE;
    AvgValues.stateOfCharge = Sum.stateOfCharge/ STREAM_SIZE;
    return AvgValues;
}

//BatteryChargingParameters 
void ComputeMovingAvgBMS_Data(BatteryChargingParameters *BMS_DataPtr, int WindowSize)
{
    BatteryChargingParameters AvgValues={0};
    BatteryChargingParameters Sum={0};
    
	
	int i;
 
    // Initial sum of K elements.
    for (i = 0; i < WindowSize; i++) {
        Sum.temperature= Sum.temperature + BMS_DataPtr->temperature;
	Sum.stateOfCharge= Sum.stateOfCharge + BMS_DataPtr->stateOfCharge;
	BMS_DataPtr++;
    }
 
    // Compute MA from index K
    float avg;
    for (i = WindowSize; i < STREAM_SIZE ; i++) {
        Sum.temperature -=  (BMS_DataPtr-WindowSize)->temperature;
	Sum.stateOfCharge -=(BMS_DataPtr-WindowSize)->stateOfCharge;
        Sum.temperature += BMS_DataPtr->temperature;
	Sum.stateOfCharge += BMS_DataPtr->stateOfCharge;
        AvgValues.temperature = Sum.temperature / WindowSize;
        AvgValues.stateOfCharge = Sum.stateOfCharge / WindowSize;
    }
	printf("Mobving avearge : %.2f   %.2f \n", AvgValues.temperature,AvgValues.stateOfCharge);
    //return AvgValues;
}


void BMS_Receiver(BatteryChargingParameters *BMS_DataPtr)
{
    ReadDataFromConsole(BMS_DataPtr);
    BatteryChargingParameters MinValue,MaxValue,AvgValue;
    MinValue = ComputeMinBMS_Data(BMS_DataPtr);
    MaxValue = ComputeMaxBMS_Data(BMS_DataPtr);
    AvgValue = ComputeAvgBMS_Data(BMS_DataPtr);
}
