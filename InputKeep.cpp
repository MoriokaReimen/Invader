#include<InputKeep.hpp>

InputKeep::InputKeep() : keep(10)
{
    return;
}

InputKeep::~InputKeep()
{}

void InputKeep::store(const KEY_INPUT& input)
{
    keep.push_back(input);
    return;
}

KEY_INPUT InputKeep::get()
{
    KEY_INPUT key(NONE);
    if(!keep.empty()) {
        key = keep.back();
    }

    return key;
}

void InputKeep::clear()
{
    keep.clear();

    return;
}
