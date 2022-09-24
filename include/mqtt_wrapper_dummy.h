#ifndef _MQTT_WRAPPER_DUMMY_H_
#define _MQTT_WRAPPER_DUMMY_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_mqtt_wrapper.h"

class MqttWrapperDummy: public IfMqttWrapper
{
    public:
    MqttWrapperDummy();

    virtual ~MqttWrapperDummy();

    private:
    MqttWrapperDummy(const MqttWrapperDummy& wrapper);

    public:
        virtual bool Setup();

        virtual void SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* water_controller);

        virtual bool IsConnected();

        virtual bool OnReconnect();

        virtual void OnLoop();

        virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text);

        virtual bool OnAirHumidification(const std::string& topic, bool state);
};

#endif // _MQTT_WRAPPER_DUMMY_H_