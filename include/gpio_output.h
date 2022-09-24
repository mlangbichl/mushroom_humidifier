#ifndef _GPIO_OUTPUT_H_
#define _GPIO_OUTPUT_H_

#pragma once

#include "Arduino.h"
#include "if_gpio_output.h"

class GpioOutput: public IfGpioOutput
{
    public:
    GpioOutput(uint8_t pin);

    virtual ~GpioOutput();

    private:
    GpioOutput(const GpioOutput& lhs);

    public:

    void OnSetup();

    virtual bool OnState(bool state);

    private:
    uint8_t m_pin;

};

#endif //_IF_GPIO_OUTPUT_H_