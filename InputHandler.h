#ifndef _INPUT_HANDLER_
#define _INPUT_HANDLER_

#include <SDL2/SDL.h>

class InputHandler{

public:
    // Singleton class
    static InputHandler* Instance()
    {
        if(s_pInstance == NULL)
            s_pInstance = new InputHandler();
        return s_pInstance;
    }
    // Member functions.
    void update();
    void clean();

private:
    InputHandler();
    ~InputHandler(){}

    static InputHandler* s_pInstance;

};

typedef InputHandler TheInputHandler;

#endif
