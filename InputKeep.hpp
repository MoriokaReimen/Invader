#pragma once
#include<vector>

enum KEY_INPUT {
    NONE,
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class InputKeep
{
    std::vector<KEY_INPUT> keep;
    InputKeep(const InputKeep& other);
    InputKeep& operator=(const InputKeep& other);
public:
    InputKeep();
    ~InputKeep();
    void store(const KEY_INPUT& input);
    KEY_INPUT get();
    void clear();
};

