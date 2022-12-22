#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <memory>
#include <vector>

#include "MenuExample\State.h"
#include "MenuExample\Button.h"

class MainMenuState : public State {
private:
    StateSignal state_sig = StateSignal::STAY;
    std::vector<std::unique_ptr<Button>> Buttons;
    int button_index;
public:
    MainMenuState(/* args */) {}
    ~MainMenuState() {}

    void HandleInput() override;
    void Update() override;
    void Render() override;

    StateSignal StateToManagerSignal() override { return state_sig; }
    void ResetSignal() override {state_sig = StateSignal::STAY; }

};

#endif