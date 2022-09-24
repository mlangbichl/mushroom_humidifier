#ifndef _WATER_LEVEL_CONTROLLER_H_
#define _WATER_LEVEL_CONTROLLER_H_

#pragma once

#include "Arduino.h"
#include "if_output.h"
#include "if_gpio_output.h"
#include "if_water_level_controller.h"
#include "definitions.h"

class WaterLevelController: public IfWaterLevelController
{

    private:
    enum States
    {
        EMPTY = 0,
        FILLING,
        WAITING_TILL_EMPTY,
        FULL,
        MAX
    };

    public:
    WaterLevelController(IfGpioOutput* gpio, IfOutput* output);

    virtual ~WaterLevelController();

    private:
    WaterLevelController(const WaterLevelController& wrapper);

    public:
    void OnSetup();

    virtual void OnStateChange(WaterLevel::Level level, bool state);

    virtual void OnTapWater(bool state);

    private:
    void SetState();

    void UpdateGpioState();

    const char* GetStatesString(States state);

    std::string GetMqttString();

    void DebugStates();

    private:
    IfGpioOutput* m_gpio;
    IfOutput*     m_output;
    bool    m_states[WaterLevel::MAX];
    States  m_state;
    bool    m_initial_message;
    bool    m_mqtt_state;
    States  m_state_previous;
    bool    m_level_state;
};

#endif //_WATER_LEVEL_CONTROLLER_H_