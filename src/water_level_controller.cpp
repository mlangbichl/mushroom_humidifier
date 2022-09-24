#include "water_level_controller.h"
#include "debug.h"

//----------------------------------------
WaterLevelController::WaterLevelController(IfGpioOutput* gpio, IfOutput* output):
    m_gpio(gpio),
    m_output(output),
    m_state(WaterLevelController::MAX),
    m_initial_message(false),
    m_mqtt_state(false),
    m_state_previous(WaterLevelController::MAX),
    m_level_state(false)
{

}

//----------------------------------------
WaterLevelController::~WaterLevelController()
{

}

//----------------------------------------
void WaterLevelController::OnSetup()
{
    Debug::Info("WaterLevelController::OnSetup()");
    for(uint8_t index = 0; index < WaterLevel::MAX; index++)
    {
        m_states[index] = false;
    }
}

//----------------------------------------
void WaterLevelController::OnStateChange(WaterLevel::Level level, bool state)
{
    Debug::Info("WaterLevelController::OnStateChange(); Level: ", WaterLevel::GetLevelString(level));
    if(level == WaterLevel::EMPTY)
    {
        if(state == true)
        {
            m_mqtt_state = false;
            m_gpio->OnState(m_mqtt_state);
            m_output->OnAirHumidification(Mqtt::TOPIC_WATER_TAP_STATE, m_mqtt_state);
        }
        else
        {
            m_mqtt_state = true;
            m_gpio->OnState(m_mqtt_state);
            m_output->OnAirHumidification(Mqtt::TOPIC_WATER_TAP_STATE, m_mqtt_state);
        }
    }
    /*m_states[level] = state;
    SetState();
    UpdateGpioState();
    DebugStates();*/
}

//----------------------------------------
void WaterLevelController::OnTapWater(bool state)
{
    if(m_initial_message == false)
    {
        m_initial_message = true;
    }
    else
    {
        m_mqtt_state = !m_mqtt_state;
        m_gpio->OnState(m_mqtt_state);
        m_output->OnAirHumidification(Mqtt::TOPIC_WATER_TAP_STATE, m_mqtt_state);
    }

}

//----------------------------------------
void WaterLevelController::SetState()
{
    if(m_states[WaterLevel::EMPTY] == false && m_states[WaterLevel::FULL] == false)
    {
        m_state_previous = m_state;
        m_state = WaterLevelController::FILLING;
    }
    else if(m_states[WaterLevel::EMPTY] == false && m_states[WaterLevel::FULL] == true)
    {
        m_state_previous = m_state;
        m_state = WaterLevelController::MAX;
    }
    else if(m_states[WaterLevel::EMPTY] == true && m_states[WaterLevel::FULL] == false)
    {
        if(m_state_previous != WaterLevelController::WAITING_TILL_EMPTY)
        {
            m_state_previous = m_state;
            m_state = WaterLevelController::WAITING_TILL_EMPTY;
        }
    }
        else if(m_states[WaterLevel::EMPTY] == true && m_states[WaterLevel::FULL] == true)
    {
        m_state_previous = m_state;
        m_state = WaterLevelController::FULL;
    }
    m_output->OnWaterFillingLevel(std::string(Mqtt::TOPIC_AIR_HUMIDIFIER_WATER_LEVEL), GetMqttString());
}

//----------------------------------------
void WaterLevelController::UpdateGpioState()
{
    if(m_state == WaterLevelController::FILLING)
    {
        m_mqtt_state = true;
        m_gpio->OnState(m_mqtt_state);
        m_output->OnAirHumidification(Mqtt::TOPIC_WATER_TAP_STATE, m_mqtt_state);
        
    }
    if(m_state == WaterLevelController::FULL)
    {
        m_mqtt_state = false;
        m_gpio->OnState(m_mqtt_state);
        m_output->OnAirHumidification(Mqtt::TOPIC_WATER_TAP_STATE, m_mqtt_state);
    }
}

//----------------------------------------
const char* WaterLevelController::GetStatesString(WaterLevelController::States state)
{
    const char* tmp = "HOW DID YOU COME HERE???";
    switch(state)
    {
        case WaterLevelController::EMPTY:
        tmp = "WaterLevelController::EMPTY";
        break;
        case WaterLevelController::FILLING:
        tmp = "WaterLevelController::FILLING";
        break;
        case WaterLevelController::WAITING_TILL_EMPTY:
        tmp = "WaterLevelController::WAITING_TILL_EMPTY";
        break;
        case WaterLevelController::FULL:
        tmp = "WaterLevelController::FULL";
        break;
        case WaterLevelController::MAX:
        tmp = "WaterLevelController::MAX";
        break;
    }
    return tmp;
}

//----------------------------------------
std::string WaterLevelController::GetMqttString()
{
    const char* tmp = "HOW DID YOU COME HERE???";
    switch(m_state)
    {
        case WaterLevelController::EMPTY:
        tmp = "Leer";
        break;
        case WaterLevelController::FILLING:
        tmp = "Befuellen";
        break;
        case WaterLevelController::WAITING_TILL_EMPTY:
        tmp = "Warten auf niedriges Niveau";
        break;
        case WaterLevelController::FULL:
        tmp = "Voll";
        break;
        case WaterLevelController::MAX:
        tmp = "WaterLevelController::MAX";
        break;
    }
    return tmp;
}

//----------------------------------------
void WaterLevelController::DebugStates()
{
    Debug::Info("//----------------------------------------");
    for(uint8_t index = 0; index < WaterLevel::MAX; index++)
    {
        Debug::Info("State:          ", WaterLevel::GetLevelString(static_cast<WaterLevel::Level>(index)));
        Debug::Info("StateValue:     ", static_cast<uint8_t>(m_states[index]));
        Debug::Info("State Previous: ", GetStatesString(m_state_previous));
        Debug::Info("State:          ", GetStatesString(m_state));
    }
    Debug::Info("//----------------------------------------");
}
