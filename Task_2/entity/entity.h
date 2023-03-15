#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using namespace std;

class Entity
{
public:
    Entity(int x, int y);

    int getPosX() const;
    void setPosX(int value);

    int getPosY() const;
    void setPosY(int value);

    void setPosition(int x, int y);

    bool isOnPosition(int x, int y);

    string getName() const;
    void setName(const string &value);

protected:
    int posX;
    int posY;
    string name;

};

#endif // ENTITY_H
