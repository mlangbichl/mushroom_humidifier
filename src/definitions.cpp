#include "definitions.h"

//----------------------------------------
//NetworkSetup
const char* NetworkSetup::HOSTNAME = "MushroomHumidifier\0";

#ifndef __VIENNA__
const char* NetworkSetup::SSID = "batcave\0";
const char* NetworkSetup::PASSWORD = "wpoZ.ZreWrkx7y\0";
#else
const char* NetworkSetup::SSID = "batcave-mobile\0";
const char* NetworkSetup::PASSWORD = "?6d8c3X(c>AL;MXFC.2\0";
#endif

const char* NetworkSetup::NTP_SERVER_01 = "pool.ntp.org\0";
const char* NetworkSetup::NTP_SERVER_02 = "time.nis.gov\0";

//----------------------------------------
//MQTT
const char*     Mqtt::SERVER = "192.168.1.17\0";
const uint16_t  Mqtt::PORT = 1883;
const uint16_t  Mqtt::RECONNECT_TIMEOUT  = 5; //in unit os seconds
const uint16_t  Mqtt::RECONNECT_COUNT    = 5;

const char*     Mqtt::TOPIC_MUSHROOM_BREEDING_DHT20     = "Mushroom/Breeding/DHT20\0";

const char*     Mqtt::TOPIC_AIR_HUMIDIFIER_WATER_LEVEL  = "Mushroom/Breeding/Humidifier/WaterLevel\0";
const char*     Mqtt::TOPIC_AIR_HUMIDIFIER_STATE        = "Mushroom/Breeding/Humidifier/State\0";
const char*     Mqtt::TOPIC_AIR_HUMIDIFIER_COMMAND      = "Mushroom/Breeding/Humidifier/Command\0";

const char*     Mqtt::TOPIC_WATER_TAP_STATE             = "Mushroom/Breeding/Humidifier/TapWater/State\0";
const char*     Mqtt::TOPIC_WATER_TAP_COMMAND           = "Mushroom/Breeding/Humidifier/TapWater/Command\0";

const char*    Mqtt::VALUE_STATE      = "state\0";
const char*    Mqtt::VALUE_STATE_ON   = "ON\0";
const char*    Mqtt::VALUE_STATE_OFF  = "OFF\0";
const uint8_t  Mqtt::SUBSCRIPTIONS_AMOUNT = 2;

const char* Mqtt::SUBSCRIPTIONS []=
{
  "Mushroom/Breeding/DHT20\0",
  "homeassistant/Mushroom/Humidifier/\0"
};

//----------------------------------------
// HumidifierPin
const uint8_t   HumidifierPin::HUMIDIFIER = 13;
const uint8_t   HumidifierPin::FAN        = 14;
const uint64_t  HumidifierPin::FAN_DELAY  = 30 * 1000;


//----------------------------------------
// WaterLevel
const uint8_t WaterLevel::SENSOR_LOW  = 19;
const uint8_t WaterLevel::SENSOR_HIGH = 18;
const uint8_t WaterLevel::MAGNETIC_VALVE = 27;

const WaterLevel::Config WaterLevel::S_WATER_LEVEL_CONFIG[WaterLevel::Level::MAX] =
{
  {WaterLevel::Level::EMPTY, WaterLevel::SENSOR_LOW},
  {WaterLevel::Level::FULL, WaterLevel::SENSOR_HIGH}
};

//----------------------------------------
const char* WaterLevel::GetLevelString(WaterLevel::Level level)
{
  const char* tmp = "HOW DID YOU COME HERE???\0";
  switch(level)
  {
    case WaterLevel::EMPTY:
      tmp = "WaterLevel::EMPTY\0";
    break;
    case WaterLevel::FULL:
      tmp = "WaterLevel::FULL\0";
    break;
    case WaterLevel::MAX:
    break;
  }
  return tmp;
}

//----------------------------------------
bool WaterLevel::GetWaterSensorConfig(WaterLevel::Level level, WaterLevel::Config& config)
{
  bool ret = false;
  for(uint8_t index = 0; index <= static_cast<uint8_t>(WaterLevel::Level::MAX); index++)
  {
    if(WaterLevel::S_WATER_LEVEL_CONFIG[index].m_type == level)
    {
      config = WaterLevel::S_WATER_LEVEL_CONFIG[index];
      ret = true;
      break;
    }
  }
  return ret;
}

//----------------------------------------
//Common
const uint32_t Common::BOUD_RATE = 115200;

//----------------------------------------
//Influx DB
#ifdef __DEVELOPMENT__
const char* InfluxDBDefinition::URL    = "http://192.168.1.16:8086\0";
const char* InfluxDBDefinition::BUCKET = "DEVLOPMENT_TEST";
const char* InfluxDBDefinition::TOKEN  = "KZG4psllq5sRdo2ulhNWSdm0P13Hin63gYrOuh6lWWXKV-vGtt8Ia76zCibSfj8EoMEC2WYLo_DRrfAd5tt_cQ==";
const char* InfluxDBDefinition::ORG    = "pilzhandwerk.at";
#else
const char* InfluxDBDefinition::URL    = "http://192.168.1.16:8086\0";
const char* InfluxDBDefinition::BUCKET = "pilzhandwerk.at\0";
#ifdef __CO2_SENSORS__
const char* InfluxDBDefinition::TOKEN  = "9yIHQa2ufQ0_EhALQYIAGSY1aMsIDsvOgd3LaeF3_S5wqOiy2PPR04xVfclKB9ehsIw0ZJ6DwY4p6AR6RAnBHg==";
#endif
#ifdef __DHT_SENSORS__
//const char* InfluxDBDefinition::TOKEN  = "yDxU0I18VbQstxtmSoc1IOTLSfg7TtLIZgPr3Xl1d3IuEwwd4cRd9SrvpYOvA-FuY9RqTCNlpwkWtqsdbUS0zQ==";
#endif
const char* InfluxDBDefinition::ORG    = "pilzhandwerk.at\0";
#endif
const char* InfluxDBDefinition::TIMEZONE_INFO = "CET-1CEST,M3.5.0,M10.5.0/3\0";

//----------------------------------------
//Topic
const char* Topic::BASE               = "Mushroom\0";
