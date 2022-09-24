#ifndef _IF_MQTT_WRAPPER_H_
#define _IF_MQTT_WRAPPER_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "PubSubClient.h"
#include "if_output.h"
#include "if_humidifier.h"
#include "if_water_level_controller.h"

class IfMqttWrapper: public IfOutput
{
    public:
        virtual ~IfMqttWrapper()
        {

        }

    public:
        virtual bool Setup() = 0;

        virtual void SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* water_controller) = 0;

        virtual bool IsConnected() = 0;

        virtual bool OnReconnect() = 0;

        virtual void OnLoop() = 0;

        virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text) = 0;

        virtual bool OnAirHumidification(const std::string& topic, bool state) = 0;
};

#endif 