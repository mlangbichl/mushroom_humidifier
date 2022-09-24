#include "influx_db_wrapper_dummy.h"
#include "debug.h"

//----------------------------------------
InfluxDBWrapperDummy::InfluxDBWrapperDummy()
{

}

//----------------------------------------
InfluxDBWrapperDummy::~InfluxDBWrapperDummy()
{

}

//----------------------------------------
bool InfluxDBWrapperDummy::Setup()
{
    Debug::Info("InfluxDBWrapperDummy::Setup()");
    return true;
}

//----------------------------------------
bool InfluxDBWrapperDummy::OnWrite()
{
    Debug::Info("InfluxDBWrapperDummy::OnWrite()");
    return true;
}

//----------------------------------------
bool InfluxDBWrapperDummy::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("InfluxDBWrapperDummy::OnWaterFillingLevel()");
    return true;
}

//----------------------------------------
bool InfluxDBWrapperDummy::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("InfluxDBWrapperDummy::OnAirHumidification()");
    return true;
}