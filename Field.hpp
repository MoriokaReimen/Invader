#pragma once

#include<vector>
#include<memory>
#include<GameObject.hpp>

class Field
{

    int x;
    int y;
public:
    std::vector<std::shared_ptr<GameObject>> objects;

    Field();

    void update();
    void draw();
    void display();

    int get_x() const;
    int get_y() const;
    bool is_on_field(const int& x, const int& y) const;

};
