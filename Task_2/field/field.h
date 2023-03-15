#ifndef FIELD_H
#define FIELD_H

#include "point.h"
#include <iostream>
#include <string>
#include <vector>
#include "fieldexception.h"
using namespace std;

class Field
{
public:
    Field();
    Field(int size);
    void dig(int x, int y);
    void occupied(int x, int y, string nameEntity);
    void free(int x, int y);
    void printField();
    string toString();

    string getNameEntity(int x, int y);

    int getSize();
    bool isPlanted(int x, int y);
    bool isOccupied(int x, int y);
    bool isAllHarvestsDestroyed();

protected:
    int size = 5;
    vector<vector<Point>> points;
    //Point points[SIZE][SIZE];
};

#endif // FIELD_H
