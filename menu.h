#ifndef MENU_H
#define MENU_H

#include "QPainter"
#include "menupointer.h"
#include "QKeyEvent"

class Menu
{
    bool startGame;
    int yHigher,yLower;
    MenuPointer* pointer;
public:
    Menu();
    ~Menu() = default;
    void drawBackground(QPainter* painter);
    void keyMoving(QKeyEvent *event);
    void movePointer();
    bool pressToStartGame();
    void setStartGame(bool);
    bool isMultiplayer();
    bool getStartGame();
};

#endif // MENU_H
