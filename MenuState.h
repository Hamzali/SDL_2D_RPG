#ifndef _MENU_STATE_
#define  _MENU_STATE_

#include "GameState.h"

class Button;

class MenuState : public GameState {

public:
    MenuState(){}
    ~MenuState(){}

    virtual void update(int delta);
    virtual void render();

    virtual bool onExit();
    virtual bool onEnter();

    virtual std::string getStateID() const {return s_menuID;}

private:
    static const std::string s_menuID;
    Button* b1;
};


#endif
