#ifndef _IF_WATER_LEVEL_SENSOR_H
#define _IF_WATER_LEVEL_SENSOR_H

#pragma once

#include "Arduino.h"
#include "if_water_level_controller.h"


class IfWaterLevelSensor
{
    public:
    virtual ~IfWaterLevelSensor()
    {

    };

    public:

    virtual bool OnSetup() = 0;

    virtual void OnRead() = 0;
    
    virtual bool GetState() = 0;
};

#endif //_IF_WATER_LEVEL_SENSOR_H