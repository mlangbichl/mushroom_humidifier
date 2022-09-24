#ifndef _WATER_LEVEL_SENSOR_H
#define _WATER_LEVEL_SENSOR_H

#pragma once

#include "Arduino.h"
#include "if_water_level_sensor.h"
#include "definitions.h"

class WaterLevelSensor: public IfWaterLevelSensor
{
    public:
    WaterLevelSensor(WaterLevel::Config& config, IfWaterLevelController* controller);

    virtual ~WaterLevelSensor();

    private:
    WaterLevelSensor(const WaterLevelSensor& wrapper);

    public:
    virtual bool OnSetup();

    virtual void OnRead();

    virtual bool GetState();

    private:
    bool GetPinState();

    private:
    IfWaterLevelController* m_controller;
    WaterLevel::Config m_config;
    bool    m_state;
};

#endif //_IF_WATER_LEVEL_SENSOR_H