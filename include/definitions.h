#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_
#pragma once

#include "Arduino.h"

#define __DEVELOPMENT__
//#define __VIENNA__

#define __STD_OUT_SUPPORT__
#define __MQTT__SUPPORT__
//#define __INFLUX_SUPPORT__

#define __DEBUG_INFO__
#define __DEBUG_WARNING__
#define __DEBUG_ERROR__

class NetworkSetup
{
  public:
    static const char* HOSTNAME;
    static const char* SSID;
    static const char* PASSWORD;
    static const char* NTP_SERVER_01;
    static const char* NTP_SERVER_02;
};

class Mqtt
{
  public:
    static const char*    SERVER;
    static const uint16_t PORT;
    static const uint16_t RECONNECT_TIMEOUT;
    static const uint16_t RECONNECT_COUNT;

    static const char*    TOPIC_MUSHROOM_BREEDING_DHT20;

    static const char*    TOPIC_AIR_HUMIDIFIER_WATER_LEVEL;
    static const char*    TOPIC_AIR_HUMIDIFIER_STATE;
    static const char*    TOPIC_AIR_HUMIDIFIER_COMMAND;

    static const char*    TOPIC_WATER_TAP_STATE;
    static const char*    TOPIC_WATER_TAP_COMMAND;

    static const char*    VALUE_STATE;
    static const char*    VALUE_STATE_ON;
    static const char*    VALUE_STATE_OFF;

    static const uint8_t  SUBSCRIPTIONS_AMOUNT;
    static const char*    SUBSCRIPTIONS[];

};

class HumidifierPin
{
  public:
  static const uint8_t HUMIDIFIER;
  static const uint8_t FAN;
  static const uint64_t FAN_DELAY;
};

class WaterLevel
{
  public:
  enum Level
  {
    EMPTY = 0,
    FULL,
    MAX
  };

  struct Config
  {
    WaterLevel::Level m_type;
    uint8_t           m_pin;
  };

  static const uint8_t SENSOR_LOW;
  static const uint8_t SENSOR_HIGH;

  static const uint8_t MAGNETIC_VALVE;

  static const char* GetLevelString(Level level);

  static  bool GetWaterSensorConfig(Level level, WaterLevel::Config& config);

  static const Config S_WATER_LEVEL_CONFIG[];

};


class Common
{
  public:
    static const uint32_t BOUD_RATE;

    class Output
    {
      public:
      enum Type
      {
        STD_OUT = 0,
        MQTT,
        INFLUX,
        MAX
      };
    };
};

class InfluxDBDefinition
{
  public:
    static const char* URL;
    static const char* BUCKET;
    static const char* TOKEN;
    static const char* ORG;
    static const char* TIMEZONE_INFO;
};

class Topic
{
  public:
    static const char* BASE;


};

#endif 
