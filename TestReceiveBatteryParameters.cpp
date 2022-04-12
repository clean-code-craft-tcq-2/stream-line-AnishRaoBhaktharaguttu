#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "ReceiveBatteryParameters.h"

TEST_CASE("Test to check Receiver") 
{
   BatteryChargingParameters ReceivedData[STREAM_SIZE];
   printf("Temperature: 3.420 deg C , State of Charge: 11.060\n");
   batteryParametersReceiver(ReceivedData);
   REQUIRE(ReceivedData[0]->temperature==3.420);
   REQUIRE(ReceivedData[0]->stateOfCharge==11.060);
}
