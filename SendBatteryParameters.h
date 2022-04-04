//Define the Battery parameters Structure
typedef struct {
  float temperature;
  float stateOfCharge;
} BatteryChargingParameters;


void readBatteryParametersFromFile(BatteryChargingParameters *batteryParameters);
