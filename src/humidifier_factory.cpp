#include "humidifier_factory.h"
#include "gpio_output_factory.h"
#include "humidifier.h"
#include "definitions.h"

IfHumidifier*  HumidifierFactory::GetIfHumidifier(IfOutput* output)
{
    Humidifier* humidifier = new Humidifier();
    humidifier->OnSetup(output, 
                        GpioOutputFactory::GetIfGpioOutput(HumidifierPin::HUMIDIFIER),
                        GpioOutputFactory::GetIfGpioOutput(HumidifierPin::FAN));
    return humidifier;
}