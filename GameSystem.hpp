#pragma once
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
    static InputKeep* get_InputKeep();
    static void cleanup();
};
