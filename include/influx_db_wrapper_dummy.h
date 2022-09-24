#ifndef _INFLUX_DB_WRAPPER_DUMMY_H_
#define _INFLUX_DB_WRAPPER_DUMMY_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_influx_db_wrapper.h"

class InfluxDBWrapperDummy: public IfInfluxDBWrapper
{
    public:
    InfluxDBWrapperDummy();
    virtual ~InfluxDBWrapperDummy();

    private:
    InfluxDBWrapperDummy(const InfluxDBWrapperDummy& wrapper);

    public:
    virtual bool Setup();

    virtual bool OnWrite();

    virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text);

    virtual bool OnAirHumidification(const std::string& topic, bool state);

};

#endif //_INFLUX_DB_WRAPPER_DUMMY_H_
