#include "influx_db_wrapper.h"
#include "debug.h"

//----------------------------------------
InfluxDBWrapper::InfluxDBWrapper():
    m_client()
{

}

//----------------------------------------
InfluxDBWrapper::~InfluxDBWrapper()
{

}

//----------------------------------------
bool InfluxDBWrapper::Setup()
{
  Debug::Info("InfluxDBWrapper::Setup()");
  bool ret = false;
    /*m_client = InfluxDBClient(InfluxDBDefinition::URL,
                              InfluxDBDefinition::ORG,
                              InfluxDBDefinition::BUCKET,
                              InfluxDBDefinition::TOKEN,
                              InfluxDbCloud2CACert);*/

  m_client.setConnectionParams(InfluxDBDefinition::URL,
                              InfluxDBDefinition::ORG,
                              InfluxDBDefinition::BUCKET,
                              InfluxDBDefinition::TOKEN);
  delay(2);
  // Accurate time is necessary for certificate validation and writing in batches
  // For the fastest time sync find NTP servers in your area: https://www.pool.ntp.org/zone/
  // Syncing progress and the time will be printed to Serial.
  timeSync(InfluxDBDefinition::TIMEZONE_INFO, NetworkSetup::NTP_SERVER_01, NetworkSetup::NTP_SERVER_02);
  
  // Check server connection
  if (m_client.validateConnection())
  {
    Debug::Info("Connected to InfluxDB: ", m_client.getServerUrl());
    ret = true;
  }
  else
  {
    Debug::Info("InfluxDB connection failed: ", m_client.getLastErrorMessage().c_str());
    ret = false;
  }
  return ret;
}

//----------------------------------------
bool InfluxDBWrapper::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("InfluxDBWrapperDummy::OnWaterFillingLevel()");
    return true;
}

//----------------------------------------
bool InfluxDBWrapper::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("InfluxDBWrapperDummy::OnAirHumidification()");
    return true;
}

//----------------------------------------
/*bool InfluxDBWrapper::OnWrite()
{
  Debug::Info("InfluxDBWrapper::OnWrite()");
  bool ret = false;
  // Data point
//  Point sensor(Topic::BASE);
  // Add tags
//  sensor.addTag("Location", Sensor::GetLocationStr(location));
//  sensor.addTag("Sensor", Sensor::GetSensorStr(type));
  
  // Clear fields for reusing the point. Tags will remain untouched
  //sensor.clearFields();

//    sensor.addField(Topic::Value::CO2,          co2);

   
  //Debug::Info("Influx Writing: ", sensor.toLineProtocol().c_str());

  // Write point
 /* if (m_client.writePoint(sensor))
  {
     ret = true;
  }
  else
  {
    Debug::Info("InfluxDB write failed: ", m_client.getLastErrorMessage().c_str());
    ret = false;
  }*/
/*  return ret;
}*/