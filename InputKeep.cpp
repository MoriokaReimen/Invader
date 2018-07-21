#include<InputKeep.hpp>

InputKeep::InputKeep() : keep(10)
{
    return;
}

InputKeep::~InputKeep()
{}

void InputKeep::push(const KEY_INPUT& input)
{
    keep.push_back(input);
    return;
}

KEY_INPUT InputKeep::pop()
{
    KEY_INPUT key(NONE);
    if(!keep.empty()) {
        key = keep.back();
    }
    keep.clear();
    return key;
}

