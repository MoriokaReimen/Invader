#include<GameSystem.hpp>
#include<InputKeep.hpp>

void GameSystem::init()
{
    input_keep = new InputKeep();
    field = new Field();
}

InputKeep* GameSystem::get_InputKeep()
{
    return input_keep;
}

void GameSystem::cleanup()
{
    delete input_keep;
    delete field;
}
