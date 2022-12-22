#ifndef LOGO_STATE_H
#define LOGO_STATE_H

#include <string>
#include <sstream>
#include <iostream>

#include "MenuExample\State.h"

class LogoState : public State {
private:
    StateSignal state_sig = StateSignal::STAY;
    int m_framesCounter;
    int frames_wait_time = 120;
    int seconds_left = 2;
    std::stringstream msg;
public:
    LogoState();
    ~LogoState() override {}

    
    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override { state_sig = StateSignal::STAY; }
};

#endif