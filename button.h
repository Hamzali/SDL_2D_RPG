#ifndef _BUTTON_
#define _BUTTON_

#include "SDLGameObject.h"

class Button : public SDLGameObject{

public:
    Button(const LoaderParams* pParams) : SDLGameObject(pParams){

    }

    virtual void draw();
    virtual void update(int delta);
    virtual void clean();

private:




};


#endif
