#include "MenuExample\MainMenuState.h"

#include <iostream>

MainMenuState::MainMenuState(){
    std::cout << "Making Buttons. " << std::endl;
    std::unique_ptr<Button> ExitButton = std::make_unique<Button>(30,130, (char*) "EXIT", 20, GREEN, BLACK, StateSignal::QUIT_APP);
    Buttons.push_back(std::move(ExitButton));
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::HandleInput(){
    if(IsKeyPressed(KEY_DOWN)){
        if(button_index == (Buttons.size()-1)){
            button_index = 0;
        } else {
            button_index++;
        }
    } else if (IsKeyPressed(KEY_UP)){
        if(button_index == 0){
            button_index = Buttons.size()-1;
        } else {
            button_index--;
        }
    } else if (IsKeyPressed(KEY_ENTER)){
        std::cout << "Menu Selection Made" << std::endl;
        state_sig = Buttons[button_index] -> Pressed();
    }
}

void MainMenuState::Update(){}

void MainMenuState::Render(){
        //Add the Rectangle Selector here.
    //Create a rectangle object
    Rectangle rec = {Buttons[button_index]->GetX()-5, Buttons[button_index]->GetY()-5, Buttons[button_index]->GetW()+10, Buttons[button_index]->GetH()+10};
    
    //DrawLines of Rect
    DrawRectangleLinesEx(rec, 2, RED);
    
    //Draw the buttons
    for (auto const& btn : Buttons)
    {
        btn->DrawButton();
    }
}