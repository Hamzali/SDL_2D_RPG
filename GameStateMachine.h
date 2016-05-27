#ifndef _GAME_STATE_MACHINE_
#define  _GAME_STATE_MACHINE_

#include "GameState.h"

#include <vector>

class GameStateMachine{

public:
    void pushState(GameState*);
    void changeState(GameState*);
    void popState();

    void render();
    void update(int delta);

    GameState* getState() const {return m_gameStates.back();}

private:
    std::vector<GameState*> m_gameStates;

};

#endif
