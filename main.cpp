#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;

int main(int argc, char const *argv[]) {
    // To control the fixed frame rate of the program.
    Uint32 frameStart, frameTime;

    if(Game::Instance() -> init("Win", 100, 100, 640, 480, SDL_WINDOW_RESIZABLE)){

        frameStart = SDL_GetTicks(); // take the initial time.

        while(Game::Instance() -> isRunnig()){

            Game::Instance() -> render();
            Game::Instance() -> update();
            Game::Instance() -> handleEvent();

        }
        frameTime = SDL_GetTicks() - frameStart; // Find the passed time while updating.

        if(frameTime < DELAY_TIME)SDL_Delay((int) (DELAY_TIME - frameTime)); // wait for 1 - pased time seconds.

    }else {
        std::cout << "Could not init the SDL!" << std::endl;
        return -1;
    }

    Game::Instance() -> clean();
    return 0;
}
