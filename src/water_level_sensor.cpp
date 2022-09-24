#include "water_level_sensor.h"
#include "debug.h"


//----------------------------------------
WaterLevelSensor::WaterLevelSensor(WaterLevel::Config& config, IfWaterLevelController* controller):
    m_controller(controller),
    m_config(config),
    m_state(false)
{

}

//----------------------------------------
WaterLevelSensor::~WaterLevelSensor()
{

}

//----------------------------------------
bool WaterLevelSensor::OnSetup()
{
    Debug::Info("WaterLevelSensor::OnSetup(); Pin: ", m_config.m_pin);
    pinMode(m_config.m_pin, INPUT_PULLUP);
    m_state = GetPinState();
    Debug::Info("WaterLevelSensor::OnSetup(); SensorType: ", WaterLevel::GetLevelString(m_config.m_type));
    Debug::Info("State: ", static_cast<uint8_t>(m_state));
    m_controller->OnStateChange(m_config.m_type, m_state);
    return true;
}

//----------------------------------------
void WaterLevelSensor::OnRead()
{
    bool tmp = GetPinState();
    if(tmp != m_state)
    {
        m_state = tmp;
        Debug::Info("WaterLevelSensor::OnRead(); Sensor: ", WaterLevel::GetLevelString(m_config.m_type));
        Debug::Info("State: ", static_cast<uint8_t>(m_state));
        m_controller->OnStateChange(m_config.m_type, m_state);
    }
}

//----------------------------------------
bool WaterLevelSensor::GetState()
{
    return m_state;
}

//----------------------------------------
bool WaterLevelSensor::GetPinState()
{
    bool tmp = false;
    if(digitalRead(m_config.m_pin) == 0)
    {
        tmp = true;
    }
    else
    {
        tmp = false;
    }
    return tmp;
}