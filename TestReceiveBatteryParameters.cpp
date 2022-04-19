#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "ReceiveBatteryParameters.h"
#include <stdio.h>

TEST_CASE("Test to check Receiver") 
{ 
   BatteryChargingParameters ReceivedData[STREAM_SIZE], ExpectedData[STREAM_SIZE], Max, Min,Avg;
   ReadDataFromConsole(ReceivedData);
   float Temperature, StateOfCharge,ChargeRate;
    
   FILE * file= fopen("./batteryParameters.txt","r");                                                                  
   for(int i = 0 ; i < STREAM_SIZE; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0;fscanf(file, "%f\t%f\n", &Temperature,&StateOfCharge)!=EOF ;i++)
        {
            ExpectedData[i].temperature = Temperature;
            ExpectedData[i].stateOfCharge = StateOfCharge;
        }
     }
       
     REQUIRE( (ReceivedData[i].temperature - ExpectedData[i].temperature) <= 0.001);
     REQUIRE( (ReceivedData[i].stateOfCharge - ExpectedData[i].stateOfCharge) <= 0.001);
   }
   fclose(file);
    Min= ComputeMinBMSParameter(ReceivedData);
    Max = ComputeMaxBMSParameter(ReceivedData);
    Avg = ComputeAvgBMSParameter(ReceivedData);
    REQUIRE( (Min.temperature - 0 ) <=0.001);
    REQUIRE( (Max.temperature - 0 ) <=0.001);
    REQUIRE( (Avg.temperature - 0 ) <=0.001);
    REQUIRE( (Min.stateOfCharge - 0 ) <=0.001);
    REQUIRE( (Max.stateOfCharge - 0 ) <=0.001);
    REQUIRE( (Avg.stateOfCharge - 0 ) <=0.001);
   
}
