#ifndef _INFLUX_DB_WRAPPER_H_
#define _INFLUX_DB_WRAPPER_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_influx_db_wrapper.h"
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>

class InfluxDBWrapper: public IfInfluxDBWrapper
{
    public:
    InfluxDBWrapper();
    virtual ~InfluxDBWrapper();

    private:
    InfluxDBWrapper(const InfluxDBWrapper& wrapper);

    public:
    virtual bool Setup();

    virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text);

    virtual bool OnAirHumidification(const std::string& topic, bool state);

    private:
    static const uint16_t JSON_DOC_SIZE;

    InfluxDBClient m_client;
};

#endif 