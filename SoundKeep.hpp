#pragma once
#include<map>
#include<SDL2/SDL_mixer.h>

enum SoundID {
    SHOOT_SOUND,
    EXPLODE_SOUND

};

class SoundKeep
{
    SoundKeep(const SoundKeep& other) = delete;
    SoundKeep operator=(const SoundKeep& other) = delete;
    std::map<SoundID, Mix_Chunk*> sounds_;
public:
    SoundKeep();
    ~SoundKeep();
    bool registerSound(const SoundID& id, const std::string& path);
    Mix_Chunk* getSound(const SoundID& id);
};
