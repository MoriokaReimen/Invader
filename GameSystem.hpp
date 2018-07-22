#pragma once
#include<GameSystem.hpp>
#include<InputKeep.hpp>
#include<Field.hpp>

class GameSystem
{
    static InputKeep* input_keep;
    static Field* field;

    GameSystem();
    GameSystem(const GameSystem& other);
    ~GameSystem();
    GameSystem& operator=(const GameSystem& other);

public:
    static void init();
    static InputKeep* getInputKeep();
    static Field* getField();
    static void cleanup();
};
