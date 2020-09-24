#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "game.h"
#include <QTimer>
#include "menu.h"
#include "scoretable.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    bool mainmenu;
    bool scoremenu;
    bool gameMenu;
    Ui::Widget *ui;
    Game* game;
    QTimer* timer;
    Menu* menu;
    ScoreTable * score;
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    void DrawBackground(QPainter &p);

private slots:
    void gameUpdate();
    void goToMenu();
    void goToNextLevel();
};

#endif // WIDGET_H
