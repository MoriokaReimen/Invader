#pragma once
#include<Screen.hpp>

enum OBJECT_TYPE
{
    FIELD,
    PLAYER,

    OBJECT_TYPE_COUNT
};

class GameObject
{
    int x_, y_;
    bool is_alive_;
    OBJECT_TYPE type_;
    GameObject();

public:
    GameObject(const int& x, const int& y);
    GameObject(const GameObject& other);
    virtual ~GameObject();
    virtual void update() = 0;
    virtual void draw(Screen& screen);

    /* 他のゲームオブジェクトから呼び出されるメソッド */
    OBJECT_TYPE getType();
    void getPosition(int& x, int& y);
    bool isAlive();
};
