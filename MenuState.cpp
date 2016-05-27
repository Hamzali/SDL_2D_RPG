#include "MenuState.h"

#include "button.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::render()
{
    b1 -> draw();
}

void MenuState::update(int delta)
{
    b1 -> update(delta);
}

bool MenuState::onExit()
{
    std::cout << "Exited menu state!" << std::endl;
    return true;
}

bool MenuState::onEnter()
{
    std::cout << "Entered menu state!" << std::endl;

    b1 = new Button(new LoaderParams(10, 10, 186, 156/3, "button"));



    return true;
}
