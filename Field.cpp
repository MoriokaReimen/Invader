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
    this->objects_.emplace_back(std::shared_ptr<GameObject>(new Player(40, 38)));

    for(int i = 25; i < 55; ++i)
        for(int j = 1; j < 4; ++j)
            this->objects_.emplace_back(std::shared_ptr<GameObject>(new Enemy(i, j)));

    return;
}

void Field::update()
{
    GameStatus* status = GameSystem::getStatus();
    if(0 == this->countEnemy())
    {
        status -> setPlayerWin();
    }

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
            it++) {
        (*it)->getPosition(pos_x, pos_y);
        if(pos_x == x && pos_y == y)
            return *it;
    }

    return std::shared_ptr<GameObject>();
}

bool Field::checkPosition(const int& x, const int& y) const
{
    int pos_x(0);
    int pos_y(0);

    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++) {
        (*it)->getPosition(pos_x, pos_y);
        if(pos_x == x && pos_y == y)
            return true;
    }

    return false;
}

int Field::countEnemy() const
{
    int count(0);
    OBJECT_TYPE type;

    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++) {
        type = (*it)->getType();
        if(type == ENEMY) count++;
    }

    return count;
}

