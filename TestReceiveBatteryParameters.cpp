#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "ReceiveBatteryParameters.h"
#include <stdio.h>

TEST_CASE("Test to check Receiver") 
{ 
   BatteryChargingParameters ReceivedData[STREAM_SIZE], ExpectedData[STREAM_SIZE];
   ReadDataFromConsole(ReceivedData);
    float Temperature, StateOfCharge,ChargeRate;
    
    }
   FILE * file= fopen("./Sender/Sender.txt","r");                                                                  
   for(int i = 0 ; i < STREAM_SIZE; i++)
   {
     if (file!=NULL) {
        for(int i=0;fscanf(file, "%f\t%f\t%f\n", &Temperature,&StateOfCharge)!=EOF ;i++)
        {
            ExpectedData[i].temperature = Temperature;
            ExpectedData[i].stateOfCharge = StateOfCharge;
        }
       
     REQUIRE(ReceivedData[i].temperature==ExpectedData[i].temperature);
     REQUIRE(ReceivedData[i].stateOfCharge==ExpectedData[i].stateOfCharge);
   }
   fclose(file);
}
