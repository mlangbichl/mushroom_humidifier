#ifndef _IF_INFLUX_DB_WRAPPER_H_
#define _IF_INFLUX_DB_WRAPPER_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_output.h"

class IfInfluxDBWrapper: public IfOutput
{
    public:
    virtual ~IfInfluxDBWrapper()
    {

    };

    public:
    virtual bool Setup() = 0;

    virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text) = 0;

    virtual bool OnAirHumidification(const std::string& topic, bool state) = 0;

};

#endif //_IF_INFLUX_DB_WRAPPER_H_