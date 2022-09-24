#ifndef _HUMIDIFIER_H_
#define _HUMIDIFIER_H_

#pragma once

#include "Arduino.h"
#include "if_humidifier.h"
#include "if_gpio_output.h"
#include "if_output.h"
#include "definitions.h"

class Humidifier: public IfHumidifier
{

    public:
    Humidifier();

    virtual ~Humidifier();

    private:
    Humidifier(const Humidifier& wrapper);

    public:

    void OnSetup(IfOutput* output, 
                 IfGpioOutput*  if_humidifier,
                 IfGpioOutput*   if_fan);

    virtual bool OnState(bool state);

    virtual void OnLoop();


    private:
    IfOutput*       m_if_output;
    IfGpioOutput*   m_if_humidifier;
    IfGpioOutput*   m_if_fan;
    bool            m_state;
    bool            m_initial_message;

    uint64_t        m_previous_time;

};

#endif //_IF_HUMIDIFIER_H_