#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "SendBatteryParameters.h"


TEST_CASE("Test to check Sender") 
{
  BatteryChargingParameters batteryChargingParameters;
  readBatteryParametersFromFile(batteryChargingParameters);
  // Send the battery parameters to console
  batteryParametersSender(batteryChargingParameters);
}
