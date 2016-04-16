#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

// Joystick initialising.
void InputHandler::initialiseJoystick()
{
    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    if(SDL_NumJoysticks() > 0){
        for(int i = 0; i < SDL_NumJoysticks(); i++)
        {
                SDL_Joystick* joy = SDL_JoystickOpen(i);
                if(joy != NULL){// if it opened successfully.
                    m_joysticks.push_back(joy);
                    m_joystickValues.push_back(std::make_pair(new Vector2D(), new Vector2D()));

                    // Init buttons for each Joystick.
                    std::vector<bool> tempButtons;
                    for (int i = 0; i < SDL_JoystickNumButtons(joy); i++) {
                        tempButtons.push_back(false);
                    }

                    m_buttonStates.push_back(tempButtons);
                }

                else
                    std::cout << SDL_GetError() << std::endl;
        }
        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoystickInit = true;
        std::cout << "Initialised" << m_joysticks.size() << " Joystick(s)." << std::endl;
    }else {
        std::cout << "Could'nt initialised." << std::endl;
        m_bJoystickInit = false;
    }
}

int InputHandler::xValue(int joy, int stick)
{
    if(m_joystickValues.size() > 0){
        if(stick == 1) // left stick
        {
            return m_joystickValues[joy].first -> getX();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second -> getX();
        }
    }

    return 0;
}

int InputHandler::yValue(int joy, int stick)
{
    if(m_joystickValues.size() > 0){
        if(stick == 1) // left stick
        {
            return m_joystickValues[joy].first -> getY();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second -> getY();
        }
    }

    return 0;
}


bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keyStates != 0){
        if(m_keyStates[key] == 1)
            return true;
        else
            return false;
    }

    return false;
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        m_keyStates = (Uint8*)SDL_GetKeyboardState(0);
        switch (event.type) {
            case SDL_QUIT:
                TheGame::Instance() -> quit();
                break;
            case SDL_JOYAXISMOTION:
                onJoystickAxisMove(event);
                break;
            case SDL_JOYBUTTONDOWN:
                onJoystickButtonDown(event);
                break;
            case SDL_JOYBUTTONUP:
                onJoystickButtonUp(event);
                break;
            case SDL_MOUSEMOTION:
                //TODO: fix this onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_KEYUP:
                onKeyUp();
                break;
            default:
                break;
        }


    }

}

void InputHandler::onJoystickAxisMove(SDL_Event& event)
{
        // Which joystick moved.
        int whichOne = event.jaxis.which;

        // left stick movement.(left-right)
        if(event.jaxis.axis == 0)
        {
            if(event.jaxis.value > m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(1);
            else if(event.jaxis.value < -m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(-1);
            else
                m_joystickValues[whichOne].first -> setX(0);
        }

        // left stick movement.(up-down)
        if(event.jaxis.axis == 1)
        {
            if(event.jaxis.value > m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(1);
            else if(event.jaxis.value < -m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(-1);
            else
                m_joystickValues[whichOne].first -> setX(0);
        }

        // right stick movement.(left-right)
        if(event.jaxis.axis == 3)
        {
            if(event.jaxis.value > m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(1);
            else if(event.jaxis.value < -m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(-1);
            else
                m_joystickValues[whichOne].first -> setX(0);
        }

        // right stick movement.(up-down)
        if(event.jaxis.axis == 4)
        {
            if(event.jaxis.value > m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(1);
            else if(event.jaxis.value < -m_joystickDeadZone)
                m_joystickValues[whichOne].first -> setX(-1);
            else
                m_joystickValues[whichOne].first -> setX(0);
        }
}

void InputHandler::onJoystickButtonDown(SDL_Event& event)
{
    if(event.type == SDL_JOYBUTTONDOWN){
        int whichOne = event.jaxis.which;
        m_buttonStates[whichOne][event.jbutton.button] = true;
    }
}

void InputHandler::onJoystickButtonUp(SDL_Event& event)
{
    if(event.type == SDL_JOYBUTTONUP){
        int whichOne = event.jaxis.which;
        m_buttonStates[whichOne][event.jbutton.button] = false;
    }
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
        if(event.button.button == SDL_BUTTON_LEFT)
            m_mouseButtonStates[LEFT] = true;
        if(event.button.button == SDL_BUTTON_MIDDLE)
            m_mouseButtonStates[MIDDLE] = true;
        if(event.button.button == SDL_BUTTON_RIGHT)
            m_mouseButtonStates[RIGHT] = true;
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
        if(event.button.button == SDL_BUTTON_LEFT)
            m_mouseButtonStates[LEFT] = false;
        if(event.button.button == SDL_BUTTON_MIDDLE)
            m_mouseButtonStates[MIDDLE] = false;
        if(event.button.button == SDL_BUTTON_RIGHT)
            m_mouseButtonStates[RIGHT] = false;
}

void InputHandler::onMouseMove(SDL_Event& event)
{
    float x = event.motion.x;
    float y = event.motion.y;
    m_mousePosition->setX(x);
    m_mousePosition->setY(y);
}

void InputHandler::onKeyDown()
{

}


void InputHandler::onKeyUp()
{

}

void InputHandler::clean()
{
    // Cleaning up the opened joysticks.
    if(m_bJoystickInit)
        for(int i = 0; i < (int) m_joysticks.size(); i++)
            SDL_JoystickClose(m_joysticks[i]);

}
