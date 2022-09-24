#ifndef _OUTPUT_FACADE_H_
#define _OUTPUT_FACADE_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_output.h"
#include "if_std_out_wrapper.h"
#include "if_mqtt_wrapper.h"
#include "if_influx_db_wrapper.h"
#include "if_humidifier.h"
#include "if_water_level_controller.h"
#include <vector>

class OutputFacade: public IfOutput
{
    public:
    OutputFacade();
    virtual ~OutputFacade();

    private:
    OutputFacade(const OutputFacade& wrapper);

    public:

    void Setup();

    void SetInterfaces(IfHumidifier* humidifier, IfWaterLevelController* controller);

    virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text);

    virtual bool OnAirHumidification(const std::string& topic, bool state);

    bool IsMqttConnected();

    void OnMqttReconnect();

    void OnMqttLoop();

    private:
        void DebugTimeout(const char* msg);

    private:
        typedef std::vector<IfOutput*>              OutputContianer;
        typedef std::vector<IfOutput*>::iterator    OutputContaierIter;

        OutputContianer m_container;

        IfStdOutWrapper*    m_std_out_wrapper;
        IfMqttWrapper*      m_mqtt;
        IfInfluxDBWrapper*  m_influx;
        
};

#endif 