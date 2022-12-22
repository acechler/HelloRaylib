#ifndef STATE_H
#define STATE_H

#include <raylib.h>
#include "MenuExample\Constants.h"

enum class StateSignal{
    STAY = 0,
    POP_STATE,
    PUSH_TO_LOGO,
    PUSH_TO_MENU,
    QUIT_APP
};


class State {

private:

public:
    virtual ~State() {}
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual StateSignal StateToManagerSignal() = 0;
    virtual void ResetSignal() = 0;
};

#endif