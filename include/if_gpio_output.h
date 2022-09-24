#ifndef _IF_GPIO_OUTPUT_H_
#define _IF_GPIO_OUTPUT_H_

#pragma once

#include "Arduino.h"

class IfGpioOutput
{
    public:
    virtual ~IfGpioOutput()
    {

    };

    public:
    virtual bool OnState(bool state) = 0;

};

#endif //_IF_GPIO_OUTPUT_H_