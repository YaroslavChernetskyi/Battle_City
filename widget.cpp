#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    game = new Game();
    menu = new Menu();
    score = new ScoreTable();
    mainmenu = true;
    scoremenu= false;
    gameMenu = false;

    setFixedSize((WIDTH+2)*CELL, HEIGHT*CELL);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    timer->start(16);
}

Widget::~Widget()
{
    delete ui;
    delete game;
    delete timer;
    delete menu;
    delete score;
}

void Widget::gameUpdate()
{
    if(gameMenu)
    {
        if(!game->nextLevel()&&!game->gameOver())
        {
            game->generateEnemies();
            game->bonusCall();
            game->createShoot();
            game->moveShoot();
            game->changeDirection();
            game->bulletColision();
            game->createExplosion();
            game->collisionCall();
            game->deleteDiedObjects();
            game->tankMoving();
        }
        else if(game->nextLevel())
        {
            game->prepareLevelToRestart();
            scoremenu = true;
            gameMenu = false;
            QTimer::singleShot(5000, this, SLOT(goToNextLevel()));
            game->startNewGame(menu->isMultiplayer());
        }
        else if(game->gameOver())
        {
            game->prepareLevelToRestart();
            scoremenu = true;
            gameMenu = false;
            QTimer::singleShot(5000, this, SLOT(goToMenu()));
        }

    }
    else if(mainmenu)
    {
        if(menu->getStartGame())
        {
            mainmenu = false;
            gameMenu = true;
            menu->setStartGame(false);
            game->startNewGame(menu->isMultiplayer());
        }
    }
    update();

}

void Widget::goToMenu()
{
    scoremenu = false;
    mainmenu = true;
}

void Widget::goToNextLevel()
{
    scoremenu = false;
    gameMenu = true;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if(scoremenu)
    {
        score->drawBackground(&painter);
        score->drawPoints(&painter, game->getGameScore());
    }
    if(mainmenu)
    {
        menu->drawBackground(&painter);
    }
    if(gameMenu)
    {
        QBrush brush(Qt::gray);
        painter.setBrush(brush);
        painter.drawRect(WIDTH*CELL,0,(WIDTH+2)*CELL,HEIGHT*CELL);
        QBrush brush1(Qt::black);
        painter.setBrush(brush1);
        painter.drawRect(0,0,(WIDTH)*CELL,HEIGHT*CELL);
//        QPen pen;
//        pen.setWidth(1);
//        pen.setColor(Qt::white);
//        painter.setPen(pen);
//        for(int i = CELL;i<HEIGHT*CELL;i+=CELL)
//        {
//            painter.drawLine(0,i,WIDTH*CELL,i);
//        }
//        for(int i = CELL;i<WIDTH*CELL;i+=CELL)
//        {
//            painter.drawLine(i,0,i,HEIGHT*CELL);
//        }
        game->drawGame(&painter);
    }

}


void Widget::keyPressEvent(QKeyEvent *keyEvent)
{
    if(mainmenu)
    {
        menu->keyMoving(keyEvent);
    }
    else if(gameMenu)
    {
        game->reactionToKeyPress(keyEvent);
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
 if(gameMenu)
    {
        game->reactionToKeyRelease(event);
    }
}
