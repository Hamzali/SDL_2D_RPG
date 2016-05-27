#ifndef __GAME_OBJECT__
#define  __GAME_OBJECT__


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "LoaderParams.h"

#include <iostream>

class GameObject{  

public:
    GameObject(const LoaderParams* pParams){}
    virtual void draw() = 0;
    virtual void update(int delta) = 0;
    virtual void clean() = 0;

    virtual ~GameObject(){}
protected:


};

#endif
