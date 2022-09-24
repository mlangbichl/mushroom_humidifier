#include "gpio_output.h"
#include "debug.h"

//----------------------------------------
GpioOutput::GpioOutput(uint8_t pin):
    m_pin(pin)
{

}

//----------------------------------------
GpioOutput::~GpioOutput()
{

}

//----------------------------------------
void GpioOutput::OnSetup()
{
    Debug::Info("GpioOutput::OnSetup(); Pin: ", m_pin);
    pinMode(m_pin, OUTPUT);
}

//----------------------------------------
bool GpioOutput::OnState(bool state)
{
    Debug::Info("GpioOutput::OnState(); Pin:    ", m_pin);
    Debug::Info("State:                         ", static_cast<uint8_t>(state));
    uint8_t value = LOW;
    if(state == true)
    {
        value = HIGH;
    }
    digitalWrite(m_pin, value);
    return true;
}