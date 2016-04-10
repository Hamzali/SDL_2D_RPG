#include "Game.h"

int main(int argc, char const *argv[]) {

    if(Game::Instance() -> init("Win", 100, 100, 640, 480, SDL_WINDOW_RESIZABLE)){

        while(Game::Instance() -> isRunnig()){

            Game::Instance() -> render();
            Game::Instance() -> update();
            Game::Instance() -> handleEvent();

            SDL_Delay(10);
        }
        
    }else {
        std::cout << "Could not init the SDL!" << std::endl;
        return -1;
    }

    Game::Instance() -> clean();
    return 0;
}
