#ifndef _MQTT_WRAPPER_H_
#define _MQTT_WRAPPER_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_mqtt_wrapper.h"
#include <PubSubClient.h>
#include <string>
#include <WiFi.h>

void Callback(char* topic, byte* message, unsigned int length);


class MqttWrapper: public IfMqttWrapper
{
    public:
        MqttWrapper(Client& client);
        virtual ~MqttWrapper();

    private:
        MqttWrapper(const MqttWrapper& wrapper);

    public:
        virtual bool Setup();

        virtual void SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* water_controller);

        virtual bool IsConnected();

        virtual bool OnReconnect();

        virtual void OnLoop();

        virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text);

        virtual bool OnAirHumidification(const std::string& topic, bool state);

        bool OnConnect();

        void OnCallback(char* topic, byte* message, unsigned int length);

    private:
        const char* GetActiveString(bool active);

        bool GetStateFromBuffer(byte* message, unsigned int length);

    private:
        IfHumidifier*           m_if_humidifier;
        IfWaterLevelController* m_if_water_controller;
        static const uint16_t TOPIC_SIZE;
        WiFiClient      m_esp_client;
        PubSubClient*   m_client;
        std::string     m_client_id;
        bool m_test;
};

#endif 
