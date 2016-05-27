#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* p_newState)
{
    m_gameStates.push_back(p_newState);
    m_gameStates.back() -> onEnter();
}

void GameStateMachine::changeState(GameState* p_newState)
{
    if(!m_gameStates.empty()){
        if(m_gameStates.back() -> getStateID() == p_newState -> getStateID()){
            return;
        }

        if(m_gameStates.back() -> onExit()){
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

    m_gameStates.push_back(p_newState);
    m_gameStates.back() -> onEnter();
}

void GameStateMachine::popState()
{
        if(!m_gameStates.empty() && m_gameStates.back() -> onExit()){
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
}

void GameStateMachine::update(int delta)
{
    if(!m_gameStates.empty())
        m_gameStates.back() -> update(delta);
}


void GameStateMachine::render()
{
    if(!m_gameStates.empty())
        m_gameStates.back() -> render();
}
