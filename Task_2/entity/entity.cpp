#include "entity.h"

Entity::Entity(int x, int y)
{
    posX = x;
    posY = y;
}




int Entity::getPosX() const
{
    return posX;
}

void Entity::setPosX(int value)
{
    posX = value;
}

int Entity::getPosY() const
{
    return posY;
}

void Entity::setPosY(int value)
{
    posY = value;
}

void Entity::setPosition(int x, int y)
{
    posX = x;
    posY = y;
}

bool Entity::isOnPosition(int x, int y)
{
    if(posX != x || posY != y){
        return false;
    }else {
        return true;
    }
}

string Entity::getName() const
{
    return name;
}

void Entity::setName(const string &value)
{
    name = value;
}
