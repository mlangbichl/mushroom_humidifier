#include "definitions.h"
#include "output_facade.h"
#include <string>
#include <WString.h>
#include "WiFi.h"
#include "debug.h"
#include "water_level_sensor_facade.h"
#include "if_humidifier.h"
#include "humidifier_factory.h"

static uint8_t TASK_CORE_WATER_LEVEL = 1;

OutputFacade m_output_facade;
WaterLevelSensorFacade m_water_level_sensor_facade;
IfHumidifier* m_if_humidifier = 0;

//----------------------------------------
void SetupSerial()
{
  Serial.begin(Common::BOUD_RATE);
  Debug::Info("Initializing: ", NetworkSetup::HOSTNAME);  
}

//----------------------------------------
void SetupWifi()
{
  // We start by connecting to a WiFi network
  Debug::Info("//----------------------------------------");
  Debug::Info("Connecting to ", NetworkSetup::SSID);
  WiFi.hostname(NetworkSetup::HOSTNAME);
  WiFi.begin(NetworkSetup::SSID, NetworkSetup::PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Debug::Info("WiFi connected");
  String ip = WiFi.localIP().toString() + "/" + WiFi.subnetMask().toString();
  Debug::Info("IP address:  ", ip.c_str());
  Debug::Info("MAC Address: ", WiFi.macAddress().c_str());
  Debug::Info("Gateway:     ", WiFi.gatewayIP().toString().c_str());
  Debug::Info("DNS:         ", WiFi.dnsIP().toString().c_str());
  Debug::Info("RSSI:        ", WiFi.RSSI());
  Debug::Info("//----------------------------------------", true);
}

void OnTaskWaterLevel(void * param)
{
  Debug::Info("Task running on Core: ", xPortGetCoreID());
  
  while(true)
  {
    m_water_level_sensor_facade.OnRead();
    Debug::Info("Task Running");
    yield();
    delay(200);
  }
}
TaskHandle_t task_handle_water_level;

//----------------------------------------
void SetupTaskWaterLevel()
{
  Debug::Info("SetupTaskWaterLevel()");
  xTaskCreatePinnedToCore(OnTaskWaterLevel, "TaskWaterLevel", 1000, NULL, 0, &task_handle_water_level, TASK_CORE_WATER_LEVEL);
}

//----------------------------------------
void setup()
{
  SetupSerial();
  SetupWifi();
  
  m_output_facade.Setup();
  m_water_level_sensor_facade.OnSetup(&m_output_facade);
  m_if_humidifier = HumidifierFactory::GetIfHumidifier(&m_output_facade);
  m_output_facade.SetInterfaces(m_if_humidifier, m_water_level_sensor_facade.GetIfWaterLevelController());
}

//----------------------------------------
void loop()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    m_water_level_sensor_facade.OnRead();
    m_output_facade.OnMqttLoop();
  }
  else
  {
    WiFi.disconnect();
    WiFi.reconnect();
    if(WiFi.status() != WL_CONNECTED)
    {
      delay(5000);
    }
  }
}
