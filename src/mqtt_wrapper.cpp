#include "mqtt_wrapper.h"
#include "debug.h"
#include <string>
#include <WiFi.h>
#include <ArduinoJson.h>

const uint16_t MqttWrapper::TOPIC_SIZE = 1024;

static MqttWrapper* S_INSTANCE = 0;

//----------------------------------------
void Callback(char* topic, byte* message, unsigned int length)
{
    S_INSTANCE->OnCallback(topic, message, length);
}


//----------------------------------------
MqttWrapper::MqttWrapper(Client& client):
    m_if_humidifier(0),
    m_if_water_controller(0),
    m_esp_client(),
    m_client(0),
    m_client_id(""),
    m_test(false)
{
   S_INSTANCE = this;
}

//----------------------------------------
MqttWrapper::~MqttWrapper()
{

}

//----------------------------------------
bool MqttWrapper::Setup()
{
    m_client_id = std::string(NetworkSetup::HOSTNAME) + "-" + std::string(WiFi.macAddress().c_str());
    Debug::Info("MqttWrapper::Setup(); Client ID: ", m_client_id.c_str());
    m_client = new PubSubClient(m_esp_client);
    m_client->setServer(Mqtt::SERVER, Mqtt::PORT);
    m_client->setCallback(Callback);
    OnAirHumidification(std::string(Mqtt::TOPIC_AIR_HUMIDIFIER_STATE), false);
    OnAirHumidification(std::string(Mqtt::TOPIC_WATER_TAP_STATE), false);
    return OnConnect();
}

void MqttWrapper::SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* water_controller)
{
    m_if_humidifier = humidifier;
    m_if_water_controller = water_controller;
}

//----------------------------------------
bool MqttWrapper::IsConnected()
{
    bool ret = false;
    if(m_client->connected() == true)
    {
        ret = true;
    }

    return ret;
}

//----------------------------------------
void MqttWrapper::OnLoop()
{
    if(IsConnected() == false)
    {
        OnReconnect();
    }
    m_client->loop();
}

//----------------------------------------
bool MqttWrapper::OnReconnect()
{
    Debug::Info("MqttWrapper::OnReconnect()");
    return OnConnect();
}

//----------------------------------------
bool MqttWrapper::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("MqttWrapperDummy::OnWaterFillingLevel()");
    if(IsConnected() == false)
    {
        Debug::Info("MQTT Reconnect");
        OnReconnect();
    }

    bool ret = false;
    Debug::Info("MQTT Topic:  ", topic.c_str());
    Debug::Info("MQTT Buffer: ", text.c_str());

    if (m_client->publish(topic.c_str(), text.c_str()) == true)
    {
        Debug::Info("Success sending message");
        ret = true;
    }
    else
    {
        Debug::Error("Error sending message");
        ret = false;
    }
    return ret;
}

//----------------------------------------
bool MqttWrapper::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("MqttWrapperDummy::OnAirHumidification()");
    if(IsConnected() == false)
    {
        Debug::Info("MQTT Reconnect");
        OnReconnect();
    }
    bool ret = false;
    //DynamicJsonDocument doc(TOPIC_SIZE);
    //doc[Mqtt::VALUE_STATE] = GetActiveString(state);
    
    //char buffer[TOPIC_SIZE];
    //memset(buffer, '\0', sizeof(buffer));
    //serializeJson(doc, buffer);

    //Debug::Info("MQTT Topic:  ", topic.c_str());
    //Debug::Info("MQTT Buffer: ", buffer);
    const char* buffer = "OFF";
    if(state == true)
    {
        buffer = "ON";
    }

    if (m_client->publish(topic.c_str(), buffer) == true)
    {
        Debug::Info("Success sending message");
        ret = true;
    }
    else
    {
        Debug::Error("Error sending message");
        ret = false;
    }
    return ret;
}

//----------------------------------------
bool MqttWrapper::OnConnect()
{
    Debug::Info("MqttWrapper::OnConnect(); Client ID: ", m_client_id.c_str());
    bool ret = false;
    uint8_t reconnect_count = 0;
    while (IsConnected() == false)
    {
        m_client->disconnect();
        Debug::Info("MQTT: Attempting MQTT connection...");
        if(m_client->connect(m_client_id.c_str()))
        {
            Debug::Info("Mqtt Connected");
            
            //m_client->subscribe(Mqtt::TOPIC_MUSHROOM_BREEDING_DHT20);
            m_client->subscribe(Mqtt::TOPIC_AIR_HUMIDIFIER_COMMAND);
            m_client->subscribe(Mqtt::TOPIC_WATER_TAP_COMMAND);
            ret = true;
        }
        else
        {
            Debug::Info("MQTT Failed, rc=", m_client->state());
            Debug::Info("try again in 5 seconds");
            delay(Mqtt::RECONNECT_TIMEOUT * 1000);
            ret = false;
            reconnect_count++;
        }
        if(reconnect_count > Mqtt::RECONNECT_COUNT)
        {
            Debug::Error("MQTT Reconnect retries reached!");
            ret = false;
            break;
        }
    }
    return ret;
}

//----------------------------------------
void MqttWrapper::OnCallback(char* topic, byte* message, unsigned int length)
{
    Debug::Info("MqttWrapper::OnCallback()", topic);

    if(strcmp(topic, Mqtt::TOPIC_MUSHROOM_BREEDING_DHT20) == 0)
    {
        Debug::Info("Process Topic: ", topic);
    }
    else if(strcmp(topic, Mqtt::TOPIC_AIR_HUMIDIFIER_COMMAND) == 0)
    {
        m_if_humidifier->OnState(false);
    }
    else if(strcmp(topic, Mqtt::TOPIC_WATER_TAP_COMMAND) == 0)
    {
        Debug::Info("Process Topic: ", topic);
        m_test = !m_test;
        m_if_water_controller->OnTapWater(m_test);
        /*String messageTemp;
        for (int i = 0; i < length; i++)
        {
            messageTemp += (char)message[i];
        }
        Debug::Info("Message: ", messageTemp.c_str());
        bool input = false;
        if(messageTemp == "ON")
        {
            input = true;
        }
        else if(messageTemp == "OFF")
        {
            input = false;
        }
        Debug::Info("State: ", static_cast<uint8_t>(input));
        m_if_water_controller->OnTapWater(input);*/
/*        bool ret = GetStateFromBuffer(message, length);
        Debug::Info("State: ", static_cast<uint8_t>(ret));
        m_if_water_controller->OnTapWater(!ret);*/
    }
    else
    {
        Debug::Error("Unregisterd Topic: ", topic);
    }
}

//----------------------------------------
const char* MqttWrapper::GetActiveString(bool active)
{
    const char* tmp = Mqtt::VALUE_STATE_OFF;
    if(active == true)
    {
        tmp = Mqtt::VALUE_STATE_ON;
    }
    return tmp;
}

//----------------------------------------
bool MqttWrapper::GetStateFromBuffer(byte* message, unsigned int length)
{
    Debug::Info("MqttWrapper::GetStateFromBuffer()");
    String messageTemp;
    for (int i = 0; i < length; i++)
    {
        messageTemp += (char)message[i];
    }
    bool ret = false;
    Debug::Info("MqttWrapper::GetStateFromBuffer(): Message", messageTemp.c_str());
    DynamicJsonDocument doc(TOPIC_SIZE);
    deserializeJson(doc, messageTemp.c_str());

    const char* tmp = doc[Mqtt::VALUE_STATE];

    if(strcmp(Mqtt::VALUE_STATE_ON, tmp) == 0)
    {
        ret = true;
    }
    else if(strcmp(Mqtt::VALUE_STATE_OFF, tmp) == 0)
    {
        ret = false;
    }
    else
    {
        Debug::Error("MqttWrapper::GetStateFromBuffer(); HOW DID YOU COME HERE????");
    }
    return ret;
}