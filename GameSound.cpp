#include"GameSound.hpp"
#include<SDL2/SDL_mixer.h>
#include"SoundKeep.hpp"

GameSound::GameSound()
{
    int err = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    if(err != 0) {
        std::cout << "Failed to Init SDL_Mixer" << std::endl;
    }

    sounds_.registerSound(SHOOT_SOUND, "./asset/Shoot.wav");
    sounds_.registerSound(EXPLODE_SOUND, "./asset/Explode.wav");
    sounds_.registerSound(PLAYER_WIN_SOUND, "./asset/PlayerWin.wav");
    sounds_.registerSound(GAME_OVER_SOUND, "./asset/GameOver.wav");

    return;
}

GameSound::~GameSound()
{
    Mix_CloseAudio();
    return;
}

void GameSound::playSound(const SoundID& id)
{
    auto chunk = sounds_.getSound(id);

    Mix_PlayChannel(-1, chunk, 0);

    return;
}

void GameSound::stopSound()
{
    Mix_HaltChannel(-1);

    return;
}
