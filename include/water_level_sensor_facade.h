#ifndef _WATER_LEVEL_SENSOR_FACADE_H_
#define _WATER_LEVEL_SENSOR_FACADE_H_

#pragma once

#include "Arduino.h"
#include "if_water_level_sensor.h"
#include "if_output.h"
#include "water_level_controller.h"
#include <vector>


class WaterLevelSensorFacade
{
    public:
    WaterLevelSensorFacade();

    virtual ~WaterLevelSensorFacade();

    private:
    WaterLevelSensorFacade(const WaterLevelSensorFacade& wrapper);

    public:
    bool OnSetup(IfOutput* output);

    void OnRead();

    IfWaterLevelController* GetIfWaterLevelController();

    
    private:
    typedef std::vector<IfWaterLevelSensor*> IfWaterLevelSensorContainer;
    typedef std::vector<IfWaterLevelSensor*>::iterator IfWaterLevelSensorIter;

    IfWaterLevelSensorContainer m_container;
    WaterLevelController*       m_controller;
    IfOutput*                   m_if_output;
};

#endif //_WATER_LEVEL_SENSOR_FACADE_H_