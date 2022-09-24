#ifndef _OUTPUT_FACTORY_H_
#define _OUTPUT_FACTORY_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_std_out_wrapper.h"
#include "if_mqtt_wrapper.h"
#include "if_influx_db_wrapper.h"
#include <WiFi.h>

class OutputFactory
{
    private:
    OutputFactory();
    ~OutputFactory();

    private:
    OutputFactory(const OutputFactory& wrapper);

    public:
    static IfStdOutWrapper* GetIfStdOutWrapper();

    static IfMqttWrapper* GetIfMqttWrapper(Client& client);

    static IfInfluxDBWrapper* GetIfInfluxDBWrapper();

};

#endif // _OUTPUT_FACTORY_H_