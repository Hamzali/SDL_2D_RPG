#include "Game.h"
#include "GameStateMachine.h"
#include "GameManager.h"
#include "InputHandler.h"
#include "AudioManager.h"


GameManager* GameManager::s_pInstance = 0;

void GameManager::init(const char *title, const int fps) {
	Uint32 frameStart, frameTime;
    Uint32 deltaTime;

    srand(time(NULL));

	m_fps = fps;
	m_delay_time = 1000 / fps;

    if(Game::Instance() -> init(title, 100, 100, 640, 480, SDL_WINDOW_RESIZABLE)){

    	begin();
    	initPlayers();
        initDisplay();
        initSpawner();

        TheInputHandler::Instance() -> initialiseJoystick();

        frameStart = SDL_GetTicks();
        while(Game::Instance() -> isRunning()){
            if(!m_play) break;
            deltaTime = SDL_GetTicks() - frameStart;
			frameStart = SDL_GetTicks(); // take the initial time.

            update(deltaTime);

			frameTime = SDL_GetTicks() - frameStart; // Find the passed time while updating.
            frameStart = SDL_GetTicks();

	        if(frameTime < m_delay_time)SDL_Delay((int) (m_delay_time - frameTime)); // wait for 1 - pased time seconds.
        }

    }else {
        std::cout << "Could not init the SDL!" << std::endl;
    }

    Game::Instance() -> clean();
}

void GameManager::begin() {
    m_play = true;
}

GameObject* GameManager::addObject(GameObject* obj, int index) {
    return Game::Instance() -> m_pGameStateMachine -> getState() -> addObject(obj, index);
}

void GameManager::initPlayers() {

}

void GameManager::initDisplay() {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    m_width = DM.w;
    m_height = DM.h;
}

void GameManager::initSpawner() {

}
void GameManager::setMood(int type, bool flag) {

}

void GameManager::update(int delta) {
    Game::Instance() -> update(delta);
    Game::Instance() -> render();
    Game::Instance() -> handleEvent();

}
