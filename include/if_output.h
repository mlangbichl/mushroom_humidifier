#ifndef _IF_OUTPUT_H_
#define _IF_OUTPUT_H_

#pragma once

#include "Arduino.h"
#include <string>
#include "definitions.h"

class IfOutput
{
    public:
    virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text) = 0;

    virtual bool OnAirHumidification(const std::string& topic, bool state) = 0;

};

#endif 