#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "ReceiveBatteryParameters.h"

TEST_CASE("Test to check Receiver") 
{
   BatteryChargingParameters ReceivedData[STREAM_SIZE];
   for(int i = 0 ; i < STREAM_SIZE ;i++)
   {
      //printf("Temperature: 3.420 deg C , State of Charge: 11.060\n");
      printf("3.420 11.060\n");
   }
   ReadDataFromConsole(ReceivedData);
   REQUIRE(ReceivedData[0].temperature==3.420);
   REQUIRE(ReceivedData[0].stateOfCharge==11.060);
}
