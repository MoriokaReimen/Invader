#pragma once

#include<vector>

class Field
{

    int x;
    int y;
public:
    Field();

    void update();
    void display();

    int get_x() const;
    int get_y() const;
    bool is_on_field(const int& x, const int& y) const;

};
