#include "output_facade.h"
#include "output_factory.h"
#include "debug.h"
#include <WiFi.h>

//----------------------------------------
OutputFacade::OutputFacade():
    m_container(),
    m_std_out_wrapper(0),
    m_mqtt(0),
    m_influx(0)
{

}

//----------------------------------------
OutputFacade::~OutputFacade()
{

}

//----------------------------------------
void OutputFacade::Setup()
{
    Debug::Info("OutputFacade::Setup(): Enter");
    WiFiClient client;
    Debug::Info("WiFI Client Connected", client.connected());

    m_std_out_wrapper = OutputFactory::GetIfStdOutWrapper();
    m_mqtt = OutputFactory::GetIfMqttWrapper(client);
    m_influx = OutputFactory::GetIfInfluxDBWrapper();
    
    m_std_out_wrapper->Setup();
    m_mqtt->Setup();
    m_influx->Setup();

    m_container.push_back(m_std_out_wrapper);
    m_container.push_back(m_mqtt);
    m_container.push_back(m_influx);
}

//----------------------------------------
void OutputFacade::SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* controller)
{
    Debug::Info("OutputFacade::SetInterfaces()");
    m_mqtt->SetInterfaces(humidifier, controller);
}

//----------------------------------------
bool OutputFacade::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("OutputFacade::OnWriteText()");
    bool ret = true;
    for(OutputContaierIter iter = m_container.begin(); iter != m_container.end(); iter++)
    {
        (*iter)->OnWaterFillingLevel(topic, text);
    }
    return ret;
}

//----------------------------------------
bool OutputFacade::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("OutputFacade::OnAirHumidification()");
    bool ret = true;
    for(OutputContaierIter iter = m_container.begin(); iter != m_container.end(); iter++)
    {
        (*iter)->OnAirHumidification(topic, state);
    }
    return ret;
}

//----------------------------------------
bool  OutputFacade::IsMqttConnected()
{
    Debug::Info("OutputFacade::IsMqttConnected()");
    bool ret = true;
    ret = m_mqtt->IsConnected();
    return ret;
}

//----------------------------------------
void  OutputFacade::OnMqttReconnect()
{
    m_mqtt->OnReconnect();
}

//----------------------------------------
void  OutputFacade::OnMqttLoop()
{
    m_mqtt->OnLoop();
}