#ifndef _HUMIDIFIER_FACTORY_H_
#define _HUMIDIFIER_FACTORY_H_

#pragma once

#include "Arduino.h"
#include "if_humidifier.h"
#include "if_output.h"

class HumidifierFactory
{

    private:
    HumidifierFactory();
    ~HumidifierFactory();

    private:
    HumidifierFactory(const HumidifierFactory& wrapper);

    public:
    static IfHumidifier*  GetIfHumidifier(IfOutput* output);
};

#endif //_GPIO_OUTPUT_FACTORY_H_