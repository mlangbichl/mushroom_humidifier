#include "humidifier.h"

#include "debug.h"

//----------------------------------------
Humidifier::Humidifier():
    m_if_output(0),
    m_if_humidifier(0),
    m_if_fan(0),
    m_state(false),
    m_initial_message(false),
    m_previous_time(0)
{

}

//----------------------------------------
Humidifier::~Humidifier()
{

}

//----------------------------------------
void Humidifier::OnSetup(IfOutput*     output, 
                         IfGpioOutput* if_humidifier,
                         IfGpioOutput* if_fan)
{
    Debug::Info("Humidifier::Setup()");
    m_if_output     = output;
    m_if_humidifier = if_humidifier;
    m_if_fan        = if_fan;
}

//----------------------------------------
bool Humidifier::OnState(bool state)
{
    Debug::Info("Humidifier::OnState()");
    if(m_initial_message == false)
    {
        m_initial_message = true;
    }
    else
    {
        m_state = !m_state;
        m_if_fan->OnState(m_state);
        m_if_humidifier->OnState(m_state);
        m_if_output->OnAirHumidification(Mqtt::TOPIC_AIR_HUMIDIFIER_STATE, m_state);
    }
    return true;
}

//----------------------------------------
void Humidifier::OnLoop()
{
    uint64_t current = millis();
    if(current - m_previous_time >= HumidifierPin::FAN_DELAY)
    {
        m_previous_time = current;
    }
}