#define STREAM_SIZE 50

//Define the Battery parameters Structure
typedef struct {
  float temperature;
  float stateOfCharge;
} BatteryChargingParameters;

void sendBatteryParametersToConsole(batteryParameters);
void BatteryParametersSender(BatteryChargingParameters *batteryParameters);
void readBatteryParametersFromFile(BatteryChargingParameters *batteryParameters);
