#define STREAM_SIZE 50

//Define the Battery parameters Structure
typedef struct {
  float temperature;
  float stateOfCharge;
} BatteryChargingParameters;


void readBatteryParametersFromFile(BatteryChargingParameters *batteryParameters);
