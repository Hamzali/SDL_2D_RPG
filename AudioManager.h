#ifndef _AUDIO_MANAGER_
#define _AUDIO_MANAGER_

#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <string>
#include <map>

class AudioManager{

public:
    bool loadMusic(std::string path, std::string id);
    bool loadSoundEffect(std::string path, std::string id);

    void playMusic(std::string id);
    void playSoundEffect(std::string id, int channelNo, int loop);

    void isPlaying();

    bool init();
    void freeMusic(std::string id){
        Mix_FreeMusic(m_Musics[id]);
    }
    void freeSound(std::string id){
        Mix_FreeChunk(m_Sounds[id]);
    }
    
    static AudioManager* Instance(){
        if(s_pInstance == NULL){
            s_pInstance = new AudioManager();
            return s_pInstance;
        }
        return s_pInstance;
    }

private:
    AudioManager(){

    }
    ~AudioManager(){
    }
    static AudioManager* s_pInstance;
    int flags;
    std::map<std::string, Mix_Music*> m_Musics;
    std::map<std::string, Mix_Chunk*> m_Sounds;
};

typedef AudioManager TheAudioManager;

#endif
