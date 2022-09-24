#include "mqtt_wrapper_dummy.h"
#include "debug.h"

//----------------------------------------
MqttWrapperDummy::MqttWrapperDummy()
{

}

//----------------------------------------
MqttWrapperDummy::~MqttWrapperDummy()
{

}

//----------------------------------------
bool MqttWrapperDummy::Setup()
{
    Debug::Info("MqttWrapperDummy::Setup()");
    return true;
}

//----------------------------------------
void MqttWrapperDummy::SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* water_controller)
{

}

//----------------------------------------
bool MqttWrapperDummy::IsConnected()
{
    Debug::Info("MqttWrapperDummy::IsConnected()");
    return true;
}

//----------------------------------------
void MqttWrapperDummy::OnLoop()
{
    Debug::Info("MqttWrapperDummy::OnLoop()");
}

//----------------------------------------
bool MqttWrapperDummy::OnReconnect()
{
    Debug::Info("MqttWrapperDummy::OnReconnect()");
    return true;
}

//----------------------------------------
bool MqttWrapperDummy::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("MqttWrapperDummy::OnWaterFillingLevel()");
    return true;
}

//----------------------------------------
bool MqttWrapperDummy::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("MqttWrapperDummy::OnAirHumidification()");
    return true;
}

