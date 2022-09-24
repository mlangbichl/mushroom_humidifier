#include "output_factory.h"
#include "std_out_wrapper_dummy.h"
#include "std_out_wrapper.h"
#include "mqtt_wrapper_dummy.h"
#include "mqtt_wrapper.h"
#include "influx_db_wrapper_dummy.h"
#include "influx_db_wrapper.h"

//----------------------------------------
IfStdOutWrapper* OutputFactory::GetIfStdOutWrapper()
{
    IfStdOutWrapper* wrapper = 0;
    
    #ifdef __STD_OUT_SUPPORT__
    wrapper = new StdOutWrapper();
    #else
    wrapper = new StdOutWrapperDummy();
    #endif
    
    return wrapper;
}

//----------------------------------------
IfMqttWrapper* OutputFactory::GetIfMqttWrapper(Client& client)
{
    IfMqttWrapper* wrapper = 0;
    #ifdef __MQTT__SUPPORT__
    wrapper = new MqttWrapper(client);
    #else
    wrapper = new MqttWrapperDummy();
    #endif
    return wrapper;
}

//----------------------------------------
IfInfluxDBWrapper* OutputFactory::GetIfInfluxDBWrapper()
{
    IfInfluxDBWrapper* wrapper = 0;
    #ifdef __INFLUX_SUPPORT__
    wrapper = new InfluxDBWrapper();
    #else
    wrapper = new InfluxDBWrapperDummy();
    #endif
    return wrapper;
}
