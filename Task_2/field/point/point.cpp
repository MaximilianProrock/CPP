#include "point.h"

Point::Point()
{
    isPlanted = true;
    isOccupied = false;
    nameEntity = "";
}

bool Point::getIsPlanted() const
{
    return isPlanted;
}

void Point::setIsPlanted(bool value)
{
    isPlanted = value;
}

bool Point::getIsOccupied() const
{
    return isOccupied;
}

void Point::setIsOccupied(bool value)
{
    isOccupied = value;
}

string Point::getName() const
{
    return nameEntity;
}

void Point::setName(const string &value)
{
    nameEntity = value;
}


