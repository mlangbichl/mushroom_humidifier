#ifndef _DEBUG_H_
#define _DEBUG_H_

#pragma once

#include "Arduino.h"
#include "definitions.h"

class Debug
{
    private:
    Debug();
    ~Debug();

    private:
    Debug(const Debug& wrapper);

    enum Level
    {
        INFO,
        WARNING,
        ERROR,
        MAX
    };

    public:
    
    static void Info(const char* msg, bool delay = false);
    
    static void Info(const char* msg, const char* value, bool delay = false);

    static void Info(const char* msg, uint8_t value, bool delay = false);

    static void Info(const char* msg, uint16_t value, bool delay = false);

    static void Info(const char* msg, uint32_t value, bool delay = false);

    static void Info(const char* msg, int8_t value, bool delay = false);

    static void Info(const char* msg, int16_t value, bool delay = false);

    static void Info(const char* msg, int32_t value, bool delay = false);

    static void Info(const char* msg, float value, bool delay = false);

    static void Warning(const char* msg, bool delay = false);
    
    static void Warning(const char* msg, const char* value, bool delay = false);

    static void Warning(const char* msg, uint8_t value, bool delay = false);

    static void Warning(const char* msg, uint16_t value, bool delay = false);

    static void Warning(const char* msg, uint32_t value, bool delay = false);

    static void Warning(const char* msg, int8_t value, bool delay = false);

    static void Warning(const char* msg, int16_t value, bool delay = false);

    static void Warning(const char* msg, int32_t value, bool delay = false);

    static void Warning(const char* msg, float value, bool delay = false);

    static void Error(const char* msg, bool delay = false);
    
    static void Error(const char* msg, const char* value, bool delay = false);

    static void Error(const char* msg, uint8_t value, bool delay = false);

    static void Error(const char* msg, uint16_t value, bool delay = false);

    static void Error(const char* msg, uint32_t value, bool delay = false);

    static void Error(const char* msg, int8_t value, bool delay = false);

    static void Error(const char* msg, int16_t value, bool delay = false);

    static void Error(const char* msg, int32_t value, bool delay = false);

    static void Error(const char* msg, float value, bool delay = false);

    private:
    static void Print(Level level, const char* msg, bool delay);

    static void Print(Level level, const char* msg, const char* value, bool delay);

    static void Print(Level level, const char* msg, uint32_t value, bool delay);

    static void Print(Level level, const char* msg, int32_t value, bool delay);

    static void Print(Level level, const char* msg, float value, bool delay);

    static bool IsLevelEnabled(Level level);

    static const char* GetLevelString(Level level);

    static void OnDelay(bool delay);
};

#endif 