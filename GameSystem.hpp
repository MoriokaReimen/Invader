#pragma once
#include<GameSystem.hpp>
#include<GameStatus.hpp>
#include<InputKeep.hpp>
#include<Field.hpp>

class GameSystem
{
    static InputKeep* input_keep;
    static Field* field;
    static GameStatus* status;

    GameSystem();
    GameSystem(const GameSystem& other);
    ~GameSystem();
    GameSystem& operator=(const GameSystem& other);

public:
    static void init();
    static InputKeep* getInputKeep();
    static Field* getField();
    static GameStatus* getStatus();
    static void cleanup();
};
