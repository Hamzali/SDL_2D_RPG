#ifndef _GAME_STATE_
#define  _GAME_STATE_

#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"

class GameState{

public:
    GameState(){}
    virtual ~GameState(){}

    virtual void update(int delta) = 0;
    virtual void render() = 0;

    virtual bool onExit() = 0;
    virtual bool onEnter() = 0;

    virtual std::string getStateID() const = 0;

    GameObject* addObject(GameObject* obj, int index = -1){
        if(index == -1) index = (int)m_gameobjects.size();
        m_gameobjects.insert(m_gameobjects.begin() + index, obj);
        return obj;
    }

protected:
    std::vector<GameObject*> m_gameobjects;

};


#endif
