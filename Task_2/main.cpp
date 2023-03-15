#include <QCoreApplication>

#include "field.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    vector<Mole> moles;
//    moles.push_back(Mole(0, 0, true));
//    moles.push_back(Mole(0, 0,false));
//    moles.push_back(Mole(0, 0,true));
//    moles.push_back(Mole(0, 0,true));
//    moles.push_back(Mole(0, 0,false));

//    Game game = Game(5, moles);
    Game game = Game();
    game.printField();
    while(!game.isGameOver()){
        game.next();
        game.printField();

      }

    return a.exec();
}
