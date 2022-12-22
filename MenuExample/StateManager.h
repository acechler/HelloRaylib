
#include<memory>
#include<vector>
#include<raylib.h>

#include "MenuExample\LogoState.h"
#include "MenuExample\MainMenuState.h"

class StateManager
{
private:
    std::vector<std::unique_ptr<State>> m_StateStack;
public:
    StateManager(/* args */);
    ~StateManager();


    void HandleInput();
    void Update();
    void Render();

    void PushState(std::unique_ptr<State> state);
    void PopState();
    State* TopState();

};