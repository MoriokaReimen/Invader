#include"GameSound.hpp"

GameSound::GameSound()
{
    int err = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    if(err != 0) {
        std::cout << "Failed to Init SDL_Mixer" << std::endl;
    }

    return;
}

GameSound::~GameSound()
{
    Mix_CloseAudio();
    return;
}
