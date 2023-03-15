#ifndef GAME_H
#define GAME_H

#include <queue>
#include "mole.h"
#include "summerresident.h"
#include "field.h"

#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()

class Game
{
public:
    Game();
    Game(int size, vector<Mole> moles);

    Field getField() const;
    void setField(const Field &value);

    void next();
    bool isGameOver();

    void printField();
    string toString();
private:

protected:
    Field field;
    SummerResident summerResident = SummerResident(0, 0);
    vector<Mole> moles;

    SummerResident summerResidentMove(SummerResident summerResident);
    int findNearestMoleInd();

    Mole moleMove(Mole mole);
    void moleAction(Mole mole);
    void reproductionMoles(Mole mole, Mole anotherMole);
    Mole* getMoleByCoordinate(int x, int y);
    void destroyHarvest(int x, int y);

};

#endif // GAME_H
