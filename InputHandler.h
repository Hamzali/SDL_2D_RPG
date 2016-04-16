#ifndef _INPUT_HANDLER_
#define _INPUT_HANDLER_

#include <SDL2/SDL.h>

#include "Game.h"

enum mouse_buttons{
        LEFT = 0,
        MIDDLE = 1,
        RIGHT = 2
};

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

    // Joystick member functions.
    void initialiseJoystick();
    bool isJoystickInit(){return m_bJoystickInit;}

    int xValue(int joy, int stick);
    int yValue(int joy, int stick);
    bool getButtonStates(int joy, int button){
        return m_buttonStates[joy][button];
    }

    // Mouse member functions.
    bool getMouseButtonState(int button){
        return m_mouseButtonStates[button];
    }
    Vector2D* getMousePosition(){
        return m_mousePosition;
    }

    // Keyboard stuff.
    bool isKeyDown(SDL_Scancode key);






private:
    InputHandler(){
        // initialising mouse buttons.
        for (int i = 0; i < 3; i++)
            m_mouseButtonStates.push_back(false);

        m_joystickDeadZone = 1000;
    }
    ~InputHandler(){}

    static InputHandler* s_pInstance;

    // Joystick values.
    std::vector<SDL_Joystick*> m_joysticks;
    bool m_bJoystickInit;
    int m_joystickDeadZone;

    std::vector< std::pair<Vector2D*, Vector2D*> > m_joystickValues;
    std::vector< std::vector<bool> > m_buttonStates;

    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);


    // Mouse values and functions.
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;

    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    // Keyboard
    Uint8* m_keyStates;

    void onKeyDown();
    void onKeyUp();

};

typedef InputHandler TheInputHandler;

#endif
