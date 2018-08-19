#include"SoundKeep.hpp"
#include<iostream>

SoundKeep::SoundKeep()
{
    return;
}

SoundKeep::~SoundKeep()
{
    for(auto elem : sounds_) {
        Mix_FreeChunk(elem.second);
    }

    return;
}

bool SoundKeep::registerSound(const SoundID& id, const std::string& path)
{
    SoundID temp(id);
    Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
    if(sound != nullptr) {
        sounds_.emplace(temp, sound);
        return true;
    } else {
        std::cout << "Sound Load Error: " << path << std::endl;
    }

    return false;
}

Mix_Chunk* SoundKeep::getSound(const SoundID& id)
{
    Mix_Chunk* ret(nullptr);
    if(sounds_.count(id)) {
        ret = sounds_.at(id);
    }
    return ret;
}
