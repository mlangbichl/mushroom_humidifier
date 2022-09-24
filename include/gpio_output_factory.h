#ifndef _GPIO_OUTPUT_FACTORY_H_
#define _GPIO_OUTPUT_FACTORY_H_

#pragma once

#include "Arduino.h"
#include "if_gpio_output.h"

class GpioOutputFactory
{

    private:
    GpioOutputFactory();
    ~GpioOutputFactory();

    private:
    GpioOutputFactory(const GpioOutputFactory& wrapper);

    public:
    static IfGpioOutput*  GetIfGpioOutput(uint8_t pin);
};

#endif //_GPIO_OUTPUT_FACTORY_H_