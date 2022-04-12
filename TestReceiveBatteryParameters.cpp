#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "ReceiveBatteryParameters.h"

TEST_CASE("Test to check Receiver") 
{
   BatteryChargingParameters ReceivedData[STREAM_SIZE];
   printf("Temperature: 3.420 deg C , State of Charge: 11.060\n");
   batteryParametersReceiver(ReceivedData);
   REQUIRE(ReceivedData.temperature[0]==3.420);
   REQUIRE(ReceivedData.stateOfCharge[0]==11.060);
}
