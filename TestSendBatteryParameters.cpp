#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "SendBatteryParameters.h"


TEST_CASE("Test to check Sender") 
{
  BatteryChargingParameters batteryChargingParameters[STREAM_SIZE];
  readBatteryParametersFromFile(batteryChargingParameters);
  
    // Send the battery parameters to console
  batteryParametersSender(batteryChargingParameters);
  
  //Read the first and last values of the text file and assert they have been properly added to batteryParameters 
  float expectedBatteryParameters[2][2] = {{3.42, 11.06}, {1.34, 64.52}};

   REQUIRE(batteryChargingParameters[0].temperature == expectedBatteryParameters[0][0]);
   REQUIRE(batteryChargingParameters[0].stateOfCharge == expectedBatteryParameters[0][1]);

   REQUIRE(batteryChargingParameters[49].temperature == expectedBatteryParameters[1][0]);
   REQUIRE(batteryChargingParameters[49].stateOfCharge == expectedBatteryParameters[1][1]);
                         

}
