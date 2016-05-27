#include "AudioManager.h"

AudioManager* AudioManager::s_pInstance = NULL;

bool AudioManager::loadMusic(std::string path, std::string id)
{
    Mix_Music* p_tempMus = Mix_LoadMUS(path.c_str());
    if(p_tempMus != NULL){
        std::cout << "MUSIC Initialized!!!" << std::endl;
        m_Musics[id] = p_tempMus;
        return true;
    }
    std::cout << "Can't load the music file!" << std::endl;
    return false;
}

void AudioManager::playMusic(std::string id)
{
    if(Mix_PlayMusic(m_Musics[id], -1)){
        std::cout << "Can't Play the music! "<< std::endl;
        return;
    }
}

void AudioManager::playSoundEffect(std::string id, int channelNo, int loop)
{
    if(Mix_PlayChannel(channelNo, m_Sounds[id], loop) == -1) {
    printf("Mix_PlayChannel: %s\n",Mix_GetError());
    }
}

bool AudioManager::loadSoundEffect(std::string path, std::string id)
{

    Mix_Chunk* temp = Mix_LoadWAV(path.c_str());
    if(!temp) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
        return false;
    }

    m_Sounds[id] = temp;
    return true;
}

bool AudioManager::init()
{
    int result = 0;
    int flags = MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_OGG;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        return false;
    }

    if (flags != (result = Mix_Init(flags))) {
        printf("Could not initialize mixer (result: %d).\n", result);
        printf("Mix_Init: %s\n", Mix_GetError());
        //return false;
    }

    return true;
}
