#ifndef POINT_H
#define POINT_H
#include <entity.h>

class Point
{
public:
    Point();
    bool getIsPlanted() const;
    void setIsPlanted(bool value);

    bool getIsOccupied() const;
    void setIsOccupied(bool value);

    string getName() const;
    void setName(const string &value);

protected:
    bool isPlanted;
    bool isOccupied;
    string nameEntity;
};

#endif // POINT_H
