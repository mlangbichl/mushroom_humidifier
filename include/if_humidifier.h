#ifndef _IF_HUMIDIFIER_H_
#define _IF_HUMIDIFIER_H_

#pragma once

#include "Arduino.h"

class IfHumidifier
{
    public:
    virtual ~IfHumidifier()
    {

    };

    public:
    virtual bool OnState(bool state) = 0;

    virtual void OnLoop() = 0;

};

#endif //_IF_HUMIDIFIER_H_