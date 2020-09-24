#include "menu.h"
#include "qdebug.h"

Menu::Menu()
{
    startGame = false;
    yHigher = 230;
    yLower = 255;
    pointer = new MenuPointer(150,yHigher);
}

void Menu::drawBackground(QPainter *painter)
{
    QPixmap pixmap("://main.jpg");
    painter->drawPixmap(0, 0, (WIDTH+2)*CELL, HEIGHT*CELL, pixmap);
    pointer->draw(painter);
}

void Menu::keyMoving(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Shift)
    {
        movePointer();

    }
    if(event->key() == Qt::Key_Return)
    {
        startGame = true;
    }

}

void Menu::movePointer()
{
    if(pointer->getY()==yHigher)
    {
        pointer->setY(yLower);
    }
    else if(pointer->getY()==yLower)
    {
        pointer->setY(yHigher);
    }
}

bool Menu::pressToStartGame()
{
    return startGame;
}

void Menu::setStartGame(bool b)
{
    startGame = b;
}

bool Menu::isMultiplayer()
{
    if(pointer->getY()==yHigher)
    {
        return false;
    }
    else return true;
}

bool Menu::getStartGame()
{
    return  startGame;
}

