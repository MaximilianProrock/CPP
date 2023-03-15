#ifndef MOLE_H
#define MOLE_H
#include "entity.h"

class Mole: public Entity
{
public:
    Mole(int x, int y, bool sex);


    bool isMale() const;
    void setSex(bool value);

    bool isHide() const;
    void setHide(bool value);

protected:
    bool sex;
    bool hide = false;
};

#endif // MOLE_H
