#include<Field.hpp>

#include<memory>
#include<vector>
#include<Player.hpp>
#include<GameObject.hpp>

const int FIELD_X(150);
const int FIELD_Y(150);

Field::Field() : x(FIELD_X), y(FIELD_Y)
{
    this->objects.push_back(std::shared_ptr<GameObject>(new Player(50, 50)));

}

void Field::update()
{
    typedef std::vector<std::shared_ptr<GameObject>>::iterator ObjectIterator;
    for(ObjectIterator it = this->objects.begin();
        it != this->objects.end();
        it++) {
        (*it)->update();

    }

    return;
}
void Field::display()
{
    return;
}

int Field::get_x() const
{
    return this->x;
}

int Field::get_y() const
{
    return this->y;
}

bool Field::is_on_field(const int& x, const int& y) const
{
    if(x > this->x) return false;
    if(x < 0) return false;
    if(y > this->y) return false;
    if(y < 0) return false;
    return true;
}
