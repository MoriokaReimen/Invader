#include<Field.hpp>

#include<memory>
#include<vector>
#include<Player.hpp>
#include<Enemy.hpp>
#include<GameObject.hpp>
#include<algorithm>

const int FIELD_X(80);
const int FIELD_Y(40);

Field::Field() : x_(FIELD_X), y_(FIELD_Y)
{
    this->objects_.emplace_back(std::shared_ptr<GameObject>(new Player(50, 38)));

    for(int i = 0; i < 80; i++)
        for(int j = 0; j < 3; j++)
            this->objects_.emplace_back(std::shared_ptr<GameObject>(new Enemy(i, j)));

}

void Field::update()
{
    int object_num = this->objects_.size();
    for(int c = 0; c < object_num; c++)
        this->objects_[c]->update();

    this->reap();
    this->objects_.insert(this->objects_.end(),
                          this->new_objects_.begin(),
                          this->new_objects_.end());
    this->new_objects_.clear();

    return;
}
void Field::draw(Screen& screen)
{
    for(auto it = this->objects_.begin();
        it != this->objects_.end();
        it++) {
        (*it)->draw(screen);
    }
    return;
}

int Field::get_x() const
{
    return this->x_;
}

int Field::get_y() const
{
    return this->y_;
}

bool Field::is_on_field(const int& x, const int& y) const
{
    if(x >= this->x_ - 1) return false;
    if(x < 1) return false;
    if(y >= this->y_ - 1) return false;
    if(y < 1) return false;
    return true;
}

void Field::reap()
{
    typedef std::shared_ptr<GameObject> Elem;
    this->objects_.erase(
        std::remove_if(
            this->objects_.begin(),
            this->objects_.end(),
    [](const Elem& elem) {
        return ! elem->isAlive();
    }),
    this->objects_.end());

    return;
}

void Field::addObject(std::shared_ptr<GameObject>&& object)
{
    this->new_objects_.emplace_back(object);
    return;
}

std::shared_ptr<GameObject> Field::getObject(const int& x, const int& y)
{
    int pos_x(0);
    int pos_y(0);

    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++)
    {
        (*it)->getPosition(pos_x, pos_y);
        if(pos_x == x && pos_y == y)
            return *it;
    }

    return nullptr;
}

