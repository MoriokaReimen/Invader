#pragma once

#include<vector>
#include<memory>
#include<GameObject.hpp>

class Field
{

    int x_;
    int y_;
    std::vector<std::shared_ptr<GameObject>> objects_;
    std::vector<std::shared_ptr<GameObject>> new_objects_;
public:

    Field();

    void update();
    void draw();
    void draw(Screen& screen);
    void reap();

    int get_x() const;
    int get_y() const;
    bool is_on_field(const int& x, const int& y) const;
    void addObject(std::shared_ptr<GameObject>&& object);
    std::shared_ptr<GameObject> getObject(const int& x, const int& y);
    bool checkPosition(const int& x, const int& y) const;
    int countEnemy() const;

};
