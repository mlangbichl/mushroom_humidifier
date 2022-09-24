#include "std_out_wrapper.h"
#include "debug.h"


//----------------------------------------"
StdOutWrapper::StdOutWrapper()
{

}

//----------------------------------------"
StdOutWrapper::~StdOutWrapper()
{

}

//----------------------------------------"
bool StdOutWrapper::Setup()
{
    Debug::Info("StdOutWrapper::Setup()");   
    return true;
}

//----------------------------------------
bool StdOutWrapper::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("//----------------------------------------");
    Debug::Info("\tTopic:   ", topic.c_str());
    Debug::Info("\tText:    ", text.c_str());
    Debug::Info("//----------------------------------------");
    return true;
}

//----------------------------------------
bool StdOutWrapper::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("//----------------------------------------");
    Debug::Info("\tTopic:   ", topic.c_str());
    Debug::Info("\tState:   ", static_cast<uint8_t>(state));
    Debug::Info("//----------------------------------------");
    return true;
}

