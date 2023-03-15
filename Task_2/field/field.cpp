#include "field.h"

Field::Field()
{
    points.assign(size, vector<Point>(size));

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            points[i][j] = Point();
        }
    }
}

Field::Field(int size)
{
    this->size = size;
    points.assign(size, vector<Point>(size));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            points[i][j] = Point();
        }
    }
}

void Field::dig(int x, int y)
{
    points[x][y].setIsPlanted(false);
}


void Field::occupied(int x, int y, string nameEntity)
{
    points[x][y].setIsOccupied(true);
    points[x][y].setName(nameEntity);
}

void Field::free(int x, int y)
{
    points[x][y].setIsOccupied(false);
    points[x][y].setName("");
}

void Field::printField()
{
    cout << endl << toString() << endl;
}

string Field::toString()
{
    string str = "";
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(points[i][j].getIsPlanted()) {
                str += "[*]";
            }else {
                str += "[X]";
            }
        }
        str += "\n";
    }

    return str;
}

string Field::getNameEntity(int x, int y)
{
    return points[x][y].getName();
}


int Field::getSize()
{
    return size;
}

bool Field::isPlanted(int x, int y)
{
    if(x < 0 || x >= size || y < 0 || y >= size){
        throw FieldException();
    }
    return points[x][y].getIsPlanted();
}

bool Field::isOccupied(int x, int y)
{
    if(x < 0 || x >= size || y < 0 || y >= size){
        throw FieldException();
    }
    return points[x][y].getIsOccupied();
}

bool Field::isAllHarvestsDestroyed()
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(points[i][j].getIsPlanted()){
                return false;
            }
        }
    }
    return true;
}
