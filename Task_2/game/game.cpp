#include "game.h"

Game::Game()
{

    field.occupied(0, 0, "SR");


    moles.push_back(Mole(2, 2, true));
    field.occupied(2, 2, "MM");

    moles.push_back(Mole(3, 3, false));
    field.occupied(3, 3, "MF");
}

Game::Game(int size, vector<Mole> moles)
{
    field = Field(size);

    field.occupied(0, 0, "SR");


    this->moles = moles;
    for(int i = 0; this->moles.size(); i++){
        int x = rand() % (field.getSize());
        int y = rand() % (field.getSize());
        Mole mole = Mole(x, y, this->moles.at(i).isMale());
        this->moles.at(i) = mole;

        if(this->moles.at(i).isMale()){
            field.occupied(x, y, "MM");
        }else {
            field.occupied(x, y, "MF");
        }

    }

}

Field Game::getField() const
{
    return field;
}

void Game::setField(const Field &value)
{
    field = value;
}

void Game::next()
{

    for(int i = 0; i < moles.size(); i++){
        moles.at(i) = moleMove(moles.at(i));
        cout << endl;
    }
    this->summerResident = summerResidentMove(summerResident);
    cout << endl;
}

bool Game::isGameOver()
{
    if(moles.size() == 0){
        cout <<"All moles are catched"<<endl;
        return true;
    }
    if(field.isAllHarvestsDestroyed()){
        cout<<"All harvests are destroyed"<<endl;
        return true;
    }
    return false;
}


void Game::printField()
{
    cout << endl << toString() << endl;
}

string Game::toString()
{
    string str = "";
    for(int i = 0; i < field.getSize(); i++) {
        for(int j = 0; j < field.getSize(); j++) {
            if(field.isOccupied(i, j)){
                str += "[" + field.getNameEntity(i, j) + "]";
            }else{
                if(field.isPlanted(i, j)) {
                    str += "[**]";
                }else {
                    str += "[XX]";
                }
            }
        }
        str += "\n";
    }

    return str;
}

SummerResident Game::summerResidentMove(SummerResident summerResident)
{
    cout << "Summer Resident moves from (" << summerResident.getPosX() << ", " << summerResident.getPosY() << ") ";
    int nearestMoleInd = findNearestMoleInd();
    Mole nearestMole = moles.at(nearestMoleInd);

    field.free(summerResident.getPosX(), summerResident.getPosY());
    summerResident.setPosX(nearestMole.getPosX());
    summerResident.setPosY(nearestMole.getPosY());
    field.occupied(nearestMole.getPosX(), nearestMole.getPosY(), "SM");

    cout << "on (" << nearestMole.getPosX() << ", " << nearestMole.getPosY() << ")" << endl;

    if(!nearestMole.isHide()){
        moles.erase(moles.begin() + nearestMoleInd);
        cout << "Summer Resident catch Mole" << endl;
    }
    return summerResident;
}

int Game::findNearestMoleInd()
{
    vector<Mole> vector = moles;

    int nearestMoleInd = 0;
    Mole nearestMole = vector.at(nearestMoleInd);
    int min = nearestMole.getPosX() + nearestMole.getPosY();

    for (int i = 0; i < vector.size(); i++) {
        Mole mole = vector.at(i);
        int distance = mole.getPosX() + mole.getPosY();
        if(distance < min && !mole.isHide()){
            nearestMole = mole;
            nearestMoleInd = i;
            min = distance;
        }
    }

    return nearestMoleInd;
}


Mole Game::moleMove(Mole mole)
{

    int x = rand() % (field.getSize());
    int y = rand() % (field.getSize());
    int hideStatus = rand() % (2);
    if(field.isOccupied(x, y)){
        if(getMoleByCoordinate(x, y) != nullptr){
            reproductionMoles(mole, *getMoleByCoordinate(x, y));
        }
    }

    if(mole.isMale()){
        field.occupied(x, y, "MM");
    }else {
        field.occupied(x, y, "MF");
    }
    cout << "Mole moves from (" << mole.getPosX() << ", " << mole.getPosY() << ") ";
    field.free(mole.getPosX(), mole.getPosY());
    mole.setPosX(x);
    mole.setPosY(y);
    mole.setHide(hideStatus);


    cout << "on (" << x << ", " << y << ")" << endl;
    moleAction(mole);
    return mole;
}

void Game::moleAction(Mole mole)
{
    if(mole.isHide()){
        cout << "Mole The mole is underground"<< endl;
    }else {
        cout << "Mole on the surface" << endl;
        destroyHarvest(mole.getPosX(), mole.getPosY());
    }
}

Mole* Game::getMoleByCoordinate(int x, int y)
{
    for(int i = 0; i < moles.size(); i++){
        Mole *mole = &moles.at(i);
        if((*mole).getPosX() == x && (*mole).getPosY() == y){
            return mole;
        }
    }
    return nullptr;
}

void Game::reproductionMoles(Mole mole, Mole anotherMole)
{
    if(mole.isMale() != anotherMole.isMale()){
        int sex = rand() % (2);
        moles.push_back(Mole(mole.getPosX(), mole.getPosY(), sex));
        cout << "new Mole on (" << mole.getPosX() << ", " << mole.getPosY() << ")" << endl;
    }
}

void Game::destroyHarvest(int x, int y)
{
    int numberDestroyed = rand() % (9);
    int actualDestroyed = 0;
    for(int i = x -1; i < x + 1; i++){
        for(int j = y - 1; j < y + 1; j++){
            if(i >= 0 && i < field.getSize() && j >= 0 && j < field.getSize() && field.isPlanted(i, j) && numberDestroyed > 0){
                field.dig(i, j);
                numberDestroyed--;
                actualDestroyed++;
            }
        }
    }

    cout<<"Mole destroyed " << actualDestroyed << " harvest"<<endl;
}


