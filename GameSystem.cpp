#include<GameSystem.hpp>
#include<InputKeep.hpp>
#include<GameStatus.hpp>
#include<Field.hpp>
#include<GameStatus.hpp>

InputKeep* GameSystem::input_keep;
Field* GameSystem::field;
GameStatus* GameSystem::status;

void GameSystem::init()
{
    input_keep = new InputKeep();
    field = new Field();
    status = new GameStatus();

    return;
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
    delete status;
}

GameStatus* GameSystem::getStatus()
{
    return status;
}
