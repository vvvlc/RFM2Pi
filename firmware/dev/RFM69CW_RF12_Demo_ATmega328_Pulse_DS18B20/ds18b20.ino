#include <OneWire.h>                                                             // http://www.pjrc.com/teensy/td_libs_OneWire.html
#include <DallasTemperature.h>                                                   // http://download.milesburton.com/Arduino/MaximTemperature/DallasTemperature_LATEST.zip

#define ONEWIRE_MAX              6
#define ONEWIRE_BUS              5
#define TEMPERATURE_PRECISION    11

// Conversion time:
// 9bit:95ms, 10bit:187ms, 11bit:375ms, 12bit:750ms
#define ASYNC_DELAY              375

OneWire oneWire(ONEWIRE_BUS);
DallasTemperature sensors(&oneWire);
byte sensor_address [ONEWIRE_MAX][8];  // 8 bytes per address
byte numSensors;

void DS18B20_setup()
{
  sensors.begin();
  sensors.setWaitForConversion(false);
  numSensors = sensors.getDeviceCount();
  if (numSensors > ONEWIRE_MAX) numSensors = ONEWIRE_MAX;
  
  byte j = 0;
  while ((j < numSensors) && (oneWire.search(sensor_address[j]))) j++;
}

void DS18B20_readall()
{
  for(int j = 0;j<numSensors;j++) {
    sensors.setResolution(sensor_address[j], TEMPERATURE_PRECISION);
  }
  
  sensors.requestTemperatures();
  delay(ASYNC_DELAY);
  
  for(byte j=0;j<numSensors;j++) {
    rfm2pi.temp[j] = sensors.getTempC(sensor_address[j]) * 100;
  }
}
