#include "gpio_output_factory.h"
#include "gpio_output.h"

IfGpioOutput*  GpioOutputFactory::GetIfGpioOutput(uint8_t pin)
{
    GpioOutput* gpio = new GpioOutput(pin);
    gpio->OnSetup();
    return gpio;
}