#include "water_level_sensor_facade.h"
#include "water_level_sensor.h"
#include "gpio_output_factory.h"
#include "debug.h"


//----------------------------------------
WaterLevelSensorFacade::WaterLevelSensorFacade():
    m_container(),
    m_controller(0),
    m_if_output(0)
{

}

//----------------------------------------
WaterLevelSensorFacade::~WaterLevelSensorFacade()
{

}

//----------------------------------------
bool WaterLevelSensorFacade::OnSetup(IfOutput* output)
{
    Debug::Info("WaterLevelSensorFacade::OnSetup()");
    m_if_output = output;
    m_controller = new WaterLevelController(GpioOutputFactory::GetIfGpioOutput(WaterLevel::MAGNETIC_VALVE), m_if_output);
    m_controller->OnSetup();
    for(uint8_t index = 0; index < static_cast<uint8_t>(WaterLevel::Level::MAX); index++)
    {
        WaterLevel::Config config;
        config.m_type = WaterLevel::EMPTY;
        config.m_pin = 19;     
//        bool ret = WaterLevel::GetWaterSensorConfig(static_cast<WaterLevel::Level>(index), config);
//        if(ret == true)
//        {
            WaterLevelSensor* tmp = new WaterLevelSensor(config, m_controller);
            tmp->OnSetup();
            m_container.push_back(tmp);
 //       }
    }
    return true;
}

//----------------------------------------
void WaterLevelSensorFacade::OnRead()
{
    for(IfWaterLevelSensorIter iter = m_container.begin();
        iter != m_container.end();
        iter++)
        {
            //(*iter)->OnRead();
        }
}

//----------------------------------------
IfWaterLevelController* WaterLevelSensorFacade::GetIfWaterLevelController()
{
    return m_controller;
}