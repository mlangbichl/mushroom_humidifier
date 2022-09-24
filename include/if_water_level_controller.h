#ifndef _IF_WATER_LEVEL_CONTROLLER_H_
#define _IF_WATER_LEVEL_CONTROLLER_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"

class IfWaterLevelController
{
    public:
    virtual ~IfWaterLevelController()
    {

    };

    public:
    virtual void OnStateChange(WaterLevel::Level level, bool state) = 0;

    virtual void OnTapWater(bool state) = 0;

};

#endif //_IF_WATER_LEVEL_CONTROLLER_H_