#include "debug.h"

//----------------------------------------
void Debug::Info(const char* msg, bool delay)
{
    Print(Level::INFO, msg, delay);
}

//----------------------------------------    
void Debug::Info(const char* msg, const char* value, bool delay)
{
    Print(Level::INFO, msg, value, delay);
}

//----------------------------------------
void Debug::Info(const char* msg, uint8_t value, bool delay)
{
    Print(Level::INFO, msg, static_cast<uint32_t>(value), delay);
}

//----------------------------------------
void Debug::Info(const char* msg, uint16_t value, bool delay)
{
    Print(Level::INFO, msg, static_cast<uint32_t>(value), delay);
}

//----------------------------------------
void Debug::Info(const char* msg, uint32_t value, bool delay)
{
    Print(Level::INFO, msg, value, delay);
}

//----------------------------------------
void Debug::Info(const char* msg, int8_t value, bool delay)
{
    Print(Level::INFO, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Info(const char* msg, int16_t value, bool delay)
{
    Print(Level::INFO, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Info(const char* msg, int32_t value, bool delay)
{
    Print(Level::INFO, msg, value, delay);
}

//----------------------------------------
void Debug::Info(const char* msg, float value, bool delay)
{
    Print(Level::INFO, msg, value, delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, bool delay)
{
    Print(Level::WARNING, msg, delay);
}

//----------------------------------------   
void Debug::Warning(const char* msg, const char* value, bool delay)
{
    Print(Level::WARNING, msg, value, delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, uint8_t value, bool delay)
{
    Print(Level::WARNING, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, uint16_t value, bool delay)
{
    Print(Level::WARNING, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, uint32_t value, bool delay)
{
    Print(Level::WARNING, msg, value, delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, int8_t value, bool delay)
{
    Print(Level::WARNING, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, int16_t value, bool delay)
{
    Print(Level::WARNING, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, int32_t value, bool delay)
{
    Print(Level::WARNING, msg, value, delay);
}

//----------------------------------------
void Debug::Warning(const char* msg, float value, bool delay)
{
    Print(Level::WARNING, msg, value, delay);
}

//----------------------------------------
void Debug::Error(const char* msg, bool delay)
{
    Print(Level::ERROR, msg, delay);
}

//----------------------------------------
void Debug::Error(const char* msg, const char* value, bool delay)
{
    Print(Level::ERROR, msg, value, delay);
}

//----------------------------------------
void Debug::Error(const char* msg, uint8_t value, bool delay)
{
    Print(Level::ERROR, msg, static_cast<uint32_t>(value), delay);
}

//----------------------------------------
void Debug::Error(const char* msg, uint16_t value, bool delay)
{
    Print(Level::ERROR, msg, static_cast<uint32_t>(value), delay);
}

//----------------------------------------
void Debug::Error(const char* msg, uint32_t value, bool delay)
{
    Print(Level::ERROR, msg, value, delay);
}

//----------------------------------------
void Debug::Error(const char* msg, int8_t value, bool delay)
{
    Print(Level::ERROR, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Error(const char* msg, int16_t value, bool delay)
{
    Print(Level::ERROR, msg, static_cast<int32_t>(value), delay);
}

//----------------------------------------
void Debug::Error(const char* msg, int32_t value, bool delay)
{
    Print(Level::ERROR, msg, value, delay);
}

//----------------------------------------
void Debug::Error(const char* msg, float value, bool delay)
{
    Print(Level::ERROR, msg, value, delay);
}

//----------------------------------------
void Debug::Print(Debug::Level level, const char* msg, bool delay)
{
    if(IsLevelEnabled(level) == true)
    {
        Serial.print(GetLevelString(level));
        Serial.println(msg);
        OnDelay(delay);
    }
}

//----------------------------------------
void Debug::Print(Debug::Level level, const char* msg, const char* value, bool delay)
{
    if(IsLevelEnabled(level) == true)
    {
        Serial.print(GetLevelString(level));
        Serial.print(msg);
        Serial.print(" ");
        Serial.println(value);
        OnDelay(delay);
    }
}

//----------------------------------------
void Debug::Print(Debug::Level level, const char* msg, uint32_t value, bool delay)
{
    if(IsLevelEnabled(level) == true)
    {
        Serial.print(GetLevelString(level));
        Serial.print(msg);
        Serial.print(" ");
        Serial.println(value);
        OnDelay(delay);
    }
}

//----------------------------------------
void Debug::Print(Debug::Level level, const char* msg, int32_t value, bool delay)
{
    if(IsLevelEnabled(level) == true)
    {
        Serial.print(GetLevelString(level));
        Serial.print(msg);
        Serial.print(" ");
        Serial.println(value);
        OnDelay(delay);
    }
}

//----------------------------------------
void Debug::Print(Debug::Level level, const char* msg, float value, bool delay)
{
    if(IsLevelEnabled(level) == true)
    {
        Serial.print(GetLevelString(level));
        Serial.print(msg);
        Serial.print(" ");
        Serial.println(value, 2);
        OnDelay(delay);
    }
}


//----------------------------------------
bool Debug::IsLevelEnabled(Debug::Level level)
{
    bool ret = false;
    switch(level)
    {
        case Debug::INFO:
        #ifdef __DEBUG_INFO__
        ret = true;
        #endif
        break;
        case Debug::WARNING:
        #ifdef __DEBUG_WARNING__
        ret = true;
        #endif
        break;
        case Debug::ERROR:
        #ifdef __DEBUG_ERROR__
        ret = true;
        #endif
        break;
        case Debug::MAX:
        ret = false;
        break;
    }
    return ret;
}

//----------------------------------------
const char* Debug::GetLevelString(Debug::Level level)
{
    const char* tmp = "MAX";
    switch(level)
    {
        case Debug::INFO:
            tmp = "INFO:    ";
        break;
        case Debug::WARNING:
            tmp = "WARNING: ";
        break;
        case Debug::ERROR:
            tmp = "ERROR:   ";
        break;
        case Debug::MAX:
        break;
    }
    return tmp;
}

//----------------------------------------
void Debug::OnDelay(bool del)
{
    if(del == true)
    {
        delay(1500);
    }

}