#include<GameSystem.hpp>
#include<InputKeep.hpp>
#include<Field.hpp>

InputKeep* GameSystem::input_keep;
Field* GameSystem::field;

void GameSystem::init()
{
    input_keep = new InputKeep();
    field = new Field();
}

InputKeep* GameSystem::getInputKeep()
{
    return input_keep;
}

Field* GameSystem::getField()
{
    return field;
}

void GameSystem::cleanup()
{
    delete input_keep;
    delete field;
}
