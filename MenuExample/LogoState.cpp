#include "MenuExample\LogoState.h"

LogoState::LogoState() : m_framesCounter(0){}

void LogoState::HandleInput(){}

void LogoState::Update(){
    m_framesCounter ++;

    seconds_left = 1 + ((frames_wait_time - m_framesCounter) / 60);
    if(m_framesCounter > frames_wait_time){
        std::cout << "Over 2 seconds passed, sending signal to Push to Menu" << std::endl;
        m_framesCounter = 0;
        state_sig = StateSignal::PUSH_TO_MENU;
    } else{
        state_sig = StateSignal::STAY;
    }


}
void LogoState::Render(){
    DrawText("LOGO SCREEN", 20, 20, 30, LIGHTGRAY);
    std::stringstream msg;
    msg << "WAIT FOR " << seconds_left << " SECONDS";
    std::string strmsg = msg.str();

    DrawText(strmsg.c_str(), 20, 60, 20, GRAY);
}