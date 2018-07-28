#include<GameLogic.hpp>

enum GAME_STATUS {
    PLAYER_WIN,
    ENEMY_WIN,
    PROCEEDING

};

class GameLogic
{
public:
    void update();
    void reap();
    void resolveCollision();
    void spawnEnemy();
    void getStatus();
};
