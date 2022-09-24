#ifndef _STD_OUT_WRAPPER_H_
#define _STD_OUT_WRAPPER_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"
#include "if_std_out_wrapper.h"

class StdOutWrapper: public IfStdOutWrapper
{
    public:
    StdOutWrapper();
    virtual ~StdOutWrapper();

    private:
    StdOutWrapper(const StdOutWrapper& wrapper);

    public:
    virtual bool Setup();

    virtual bool OnWaterFillingLevel(const std::string& topic, const std::string& text);

    virtual bool OnAirHumidification(const std::string& topic, bool state);
};

#endif 