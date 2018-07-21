#pragma once
#include<vector>

enum KEY_INPUT
{
    NONE,
    UP,
    DOWN,
    RIGHT,
    LEFT
};

namespace GameSystem{

class InputKeep
{
    std::vector<KEY_INPUT> keep;
    InputKeep(const InputKeep& other);
    InputKeep& operator=(const InputKeep& other);
public:
        InputKeep();
        ~InputKeep();
        void push(const KEY_INPUT& input);
        KEY_INPUT pop();
};

extern InputKeep input_keep();

};
