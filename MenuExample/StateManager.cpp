#include "MenuExample\StateManager.h"

#include <iostream>

StateManager::StateManager(){

    std::unique_ptr<State> logoState = std::make_unique<LogoState>();
    m_StateStack.push_back(std::move(logoState));

}

StateManager::~StateManager(){}

void StateManager::HandleInput(){
    TopState() -> HandleInput();
}

void StateManager::Update(){
    TopState() -> Update();

    StateSignal UpdateSignal = TopState() -> StateToManagerSignal();

    switch(UpdateSignal){
        case StateSignal::STAY: {
            break;
        }
        case StateSignal::PUSH_TO_MENU: {
            std::cout << "Pushing to Menu " << std::endl;
            TopState() -> ResetSignal();
            std::unique_ptr<State> mainMenuState = std::make_unique<MainMenuState>();
            m_StateStack.push_back(std::move(mainMenuState));
            break;
        }
        case StateSignal::POP_STATE:{
            TopState()->ResetSignal();
            std::cout << "Popping Top State " << std::endl;
            m_StateStack.pop_back();
            break;
        }
        case StateSignal::QUIT_APP:{
            CloseWindow();
            break;
        }
    }
}

void StateManager::Render(){
    TopState() -> Render();
}

void StateManager::PushState(std::unique_ptr<State> state){
    m_StateStack.emplace_back(std::move(state));
}

void StateManager::PopState(){
    m_StateStack.pop_back();
}

State* StateManager::TopState(){
    if(m_StateStack.empty()){
        return nullptr;
    }
    return m_StateStack.back().get();
}