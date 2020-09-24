#ifndef GAME_H
#define GAME_H
#include "staticobject.h"
#include "movingobject.h"
#include "brick.h"
#include "mytank.h"
#include "myfriendtank.h"
#include "enemysimple.h"
#include "bullet.h"
#include "lifes.h"
#include "explosion.h"
#include "bulletexplosion.h"
#include "tankexplosion.h"
#include "base.h"
#include "steelbrick.h"
#include "bonus.h"
#include "enemysimplefactory.h"
#include "enemyspeedyfactory.h"
#include "level.h"
#include "gameoverlabel.h"
#include "enemysign.h"
#include "eagle.h"

class Game
{
public:
    Game();
    ~Game();
    void tankMoving();
    void changeDirection();
    void readGame();
    void readTankOfLevel();
    void reactionToKeyPress(QKeyEvent*);
    void reactionToKeyRelease(QKeyEvent*);
    void drawGame(QPainter *painter);
    bool collisionDetection(Tank*,StaticObject*);
    bool bulletCollisionDetection(Bullet*, StaticObject*);
    void bulletColision();
    void collisionCall();
    void createShoot();
    void moveShoot();
    std::array<int, 4>getGameScore();
    void deleteDiedObjects();
    void generateEnemies();
    void playersAppearance();
    void createBonus();
    void createExplosion();
    void createBase();
    void bonusCall();
    bool nextLevel();
    bool gameOver();
    void prepareLevelToRestart();
    void startNewGame(bool);
    void addFriendTank();
    void createEnemySigns();
    void gameOverLabelMove();
private:
    MyFriendTank * friendTank;
    Base* base;
    SteelBrick* steelBrick;
    MyTank* tank;
    Brick* brick;
    Bonus* bonus;
    EnemySimple* enemySimple;
    EnemySpeedy* enemySpeedy;
    EnemySimpleFactory* enemySimpleFactory;
    EnemySpeedyFactory* enemySpeedyFactory;
    Lifes* lifeScore;
    Explosion* explosion;
    Level * level;
    GameOverLabel* gameOverLabel;
    EnemySign* sign;
    Eagle* eagle;
    int enemyCounter;
    int appearanceCounter;
    int frameCounter;
    int xAppearance;
    int counter;
    int badTankCounter;
    int diedEnemies;
    int speedyKilled;
    int simpleKilled;
    char tankArray[20];
    MyTank* map[1];
    std::vector<Brick*> bricks;
    std::vector<GoodTank*> goodTanks;
    std::vector<BadTank*> enemies;
    std::vector<StaticObject*> explosions;
    std::vector<Bullet*> bullets;
    std::vector<EnemySign*> signs;
    std::array<int, 4>scoreArray;
};

#endif // GAME_H
