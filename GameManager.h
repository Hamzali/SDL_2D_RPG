#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__

#include "GameObject.h"
#include "Vector2D.h"
#include <stdlib.h>
#include <time.h>

class Button;

class GameManager {
public:
	void init(const char *title, const int fps);

	void initDisplay();

	void update(int delta);
	void begin() {
		m_play = true;
	}
	void pause() {
		m_play = false;
	}

	static GameManager* Instance()
    {
        if(s_pInstance == 0)
            s_pInstance = new GameManager();

        return s_pInstance;
    }

	int getWidth() {
		return m_width;
	}
	int getHeight() {
		return m_height;
	}

    std::vector<float> m_c;
    std::vector<float> m_s;

private:
	GameManager(){}
    ~GameManager();
	static GameManager *s_pInstance;

	bool m_play;

	int m_width;
	int m_height;

	int m_fps;
	float m_delay_time;
};

#endif
