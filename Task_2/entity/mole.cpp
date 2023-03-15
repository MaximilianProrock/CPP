#include "mole.h"

Mole::Mole(int x, int y, bool sex):Entity(x, y)
{
    this->sex = sex;
    this->name = "Mole";
}



bool Mole::isMale() const
{
    return sex;
}

void Mole::setSex(bool value)
{
    sex = value;
}

bool Mole::isHide() const
{
    return hide;
}

void Mole::setHide(bool value)
{
    hide = value;
}
