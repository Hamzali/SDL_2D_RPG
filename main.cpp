#include "GameManager.h"

const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;

int main(int argc, char const *argv[]) {
    // To control the fixed frame rate of the program.
    GameManager::Instance() -> init("Win", FPS);
    return 0;
}
