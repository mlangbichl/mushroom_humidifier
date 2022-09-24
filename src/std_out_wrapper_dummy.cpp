#include "std_out_wrapper_dummy.h"
#include "debug.h"

//----------------------------------------
StdOutWrapperDummy::StdOutWrapperDummy()
{

}

//----------------------------------------
StdOutWrapperDummy::~StdOutWrapperDummy()
{

}

//----------------------------------------
bool StdOutWrapperDummy::Setup()
{
    Debug::Info("StdOutWrapperDummy::Setup()");
    return true;
}

//----------------------------------------
bool StdOutWrapperDummy::OnWaterFillingLevel(const std::string& topic, const std::string& text)
{
    Debug::Info("StdOutWrapperDummy::OnWaterFillingLevel()");
    return true;
}

//----------------------------------------
bool StdOutWrapperDummy::OnAirHumidification(const std::string& topic, bool state)
{
    Debug::Info("StdOutWrapperDummy::OnAirHumidification()");
    return true;
}
