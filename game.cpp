#include "game.h"
#include "QDebug"
//#include "QRandomGenerator"
#include "QTimer"
#include <cstdlib>

Game::Game()
{
    level = new Level();
    enemySimpleFactory = new EnemySimpleFactory();
    enemySpeedyFactory = new EnemySpeedyFactory();
    xAppearance = 6*CELL;
    speedyKilled = 0;
    simpleKilled = 0;
}

void Game::startNewGame(bool multiplayer)
{
    if(multiplayer)
    {
        addFriendTank();
    }
    readGame();
    readTankOfLevel();
    generateEnemies();
    playersAppearance();
    frameCounter=0;
    enemyCounter = 0;
    appearanceCounter = 0;
    diedEnemies=0;
    counter = 0;
    badTankCounter = 0;
    lifeScore = new Lifes();
    base = new Base();
    createBase();
    bonus = nullptr;
    createEnemySigns();
    eagle = new Eagle(12*CELL/2,12*CELL);
    gameOverLabel = nullptr;
}

void Game::addFriendTank()
{
    friendTank = new MyFriendTank(MovingObject::Up, MYFRIENDTANK_X,MYFRIENDTANK_Y);
    goodTanks.push_back(friendTank);
}

void Game::createEnemySigns()
{
    for(int j = CELL; j<6*CELL;j+=CELL/2)
    {
        for(int i = 13*CELL+CELL/2; i<14*CELL+CELL/2; i+=CELL/2)
        {
            sign = new EnemySign(i,j);
            signs.push_back(sign);
        }
    }
}

void Game::gameOverLabelMove()
{
    gameOverLabel = new GameOverLabel(5*CELL+CELL/2,13*CELL);
}

std::array<int, 4> Game::getGameScore()
{
    scoreArray = {simpleKilled, speedyKilled,100,200};
            return scoreArray;
}

Game::~Game()
{

}

bool Game::nextLevel()
{
    if(diedEnemies==5)
    {
        return true;

    }
    else return false;
}

bool Game::gameOver()
{
    if((goodTanks.empty()||eagle->isDestroyed())&&gameOverLabel==nullptr)
    {
        gameOverLabelMove();
        return false;
    }
    else if(gameOverLabel!=nullptr)
    {
        if(gameOverLabel->isDestroyed())
        {
            delete level;
            level = new Level();
            return true;
        }
        else return false;

    }
    else return false;
}

void Game::prepareLevelToRestart()
{
    frameCounter=0;
    enemyCounter = 0;
    appearanceCounter = 0;
    diedEnemies=0;
    counter = 0;
    badTankCounter = 0;
    if(bonus!=nullptr)
    {
        delete bonus;
        bonus = nullptr;
    }
    if(gameOverLabel!=nullptr)
    {
        delete gameOverLabel;
        gameOverLabel = nullptr;
    }
    delete eagle;
for(auto obj : bullets)
{
    delete obj;
}
for(auto obj : signs)
{
    delete obj;
}
for(auto obj : bricks)
{
    delete obj;
}
for(auto obj : enemies)
{
    delete obj;
}
for(auto obj : explosions)
{
    delete obj;
}
for(auto obj : goodTanks)
{
    delete obj;
}
goodTanks.clear();
bullets.clear();
signs.clear();
bricks.clear();
enemies.clear();
explosions.clear();
}

void Game::tankMoving()
{
    frameCounter++;
    if(frameCounter%4!=0){
    if(!goodTanks.empty()){
        for (auto obj : goodTanks) {
            if(obj->getCanMove()&&!obj->isDestroyed())
            {
               obj->move();
            }
           }
        }
    }
    if(!enemies.empty()){
        for (auto obj : enemies) {
            if(obj->getCanMove()&&!obj->isDestroyed())
            {
               obj->move();
            }
        }
    }
}

void Game::changeDirection()
{
    if(!goodTanks.empty()){
        for (auto obj : goodTanks) {
                obj->setCanMove(true);
                obj->rotation();
        }
    }
    if(!enemies.empty()){
        for (auto obj : enemies) {
               obj->changeDirection();
           }
        }
}

void Game::generateEnemies()
{

    appearanceCounter++;
    if(appearanceCounter%190==0&&enemyCounter<3&&badTankCounter<20)
    {
        if(xAppearance>12*CELL)
        {
            xAppearance = 0;
        }
        for(auto& tier : enemies)
        {
            if(tier->boundRect().intersects(QRectF(xAppearance,0,tier->getWidth(),tier->getHeight()))){
                return;
            }
        }
        for(auto& tier : goodTanks)
        {
            if(tier->boundRect().intersects(QRectF(xAppearance,0,tier->getWidth(),tier->getHeight()))){
                return;
            }
        }
        if(tankArray[badTankCounter] == 's')
        {

            enemySimple = enemySimpleFactory->createTank(MovingObject:: Down, xAppearance, 0, badTankCounter);
            enemies.push_back(enemySimple);
            signs.back()->destroy();
          }
        else if(tankArray[badTankCounter] == 'c')
        {

            enemySpeedy = enemySpeedyFactory->createTank(MovingObject:: Down, xAppearance, 0, badTankCounter);
            enemies.push_back(enemySpeedy);
            signs.back()->destroy();
          }
        badTankCounter++;
        xAppearance+=6*CELL;
        enemyCounter++;
        appearanceCounter = 0;
    }
}

void Game::createBase()
{
    counter++;
    auto baseArr = base->getBasePositions();
    for(unsigned int  i = 0; i<8; i++)
    {
        for(std::vector<Brick*>::iterator br = bricks.begin(); br< bricks.end();br++)
        {
            if(static_cast<int>(baseArr[i][0])==(*br)->getX()&&baseArr[i][1]==(*br)->getY())
            {
                delete *br;
                bricks.erase(br);
            }
        }
    }
    if((counter>900&&counter%100>0&&counter%100<50)||counter>1200||counter==1)
    {
    for(unsigned int i = 0; i<8; i++)
    {
           brick = new Brick(baseArr[i][0],baseArr[i][1]);
           bricks.push_back(brick);
    }
    }
    else if(counter<1200)
    {
        for(unsigned int i = 0; i<8; i++)
        {
        steelBrick = new SteelBrick(baseArr[i][0],baseArr[i][1]);
        bricks.push_back(steelBrick);
        }
    }
    if(counter>1200)
    {
        base->setProtection(false);
        counter = 0;
    }
}

void Game::bonusCall()
{
    if(base->isProtected())
    {
        createBase();
    }

}

void Game::playersAppearance()
{
        tank = new MyTank(MovingObject::Up, MYTANK_X,MYTANK_Y);
        goodTanks.push_back(tank);
        //addFriendTank();
}

void Game::createBonus()
{
    int x = rand()%300;
    int y = rand()%300;
    if(bonus!=nullptr)
    {
        delete bonus;
    }
       bonus = new Bonus(x, y);

}

void Game::createExplosion()
{
    for (auto obj1 : bullets) {
            if(obj1->isDestroyed())
            {
                 explosion = new Explosion((obj1->getX()+obj1->getWidth()),
                                           (obj1->getY()+obj1->getHeight()),CELL,CELL, new BulletExplosion);
                 explosions.push_back(explosion);
            }
    }
    for (auto obj1 : enemies) {
            if(obj1->isDestroyed())
            {
                explosion = new Explosion((obj1->getX()+obj1->getWidth()),
                                          (obj1->getY()+obj1->getHeight()),CELL*2,CELL*2, new TankExplosion);
                explosions.push_back(explosion);
            }
    }

    for (auto obj1 : goodTanks) {
            if(obj1->isDestroyed())
            {
                explosion = new Explosion((obj1->getX()+obj1->getWidth()),
                                          (obj1->getY()+obj1->getHeight()),CELL*2, CELL*2, new TankExplosion);
                explosions.push_back(explosion);
            }
    }
}

bool Game::bulletCollisionDetection(Bullet * bul, StaticObject *sobj)
{
    auto rect1 = bul->boundRect();
    auto rect2 = sobj->boundRect();
    if(rect1.intersects(rect2))
        return true;
    else return false;
}

void Game::bulletColision()
{
    if(!bullets.empty()&&!enemies.empty()) {
        for (auto obj1 : bullets) {
            for (auto obj2 : enemies) {
                if(bulletCollisionDetection(obj1, obj2)&&obj1->getBulletID()==0) {
                    obj1->destroy();
                    obj2->destroy();
                    if(obj2->getID()==3||obj2->getID()==10||obj2->getID()==17)
                    {
                        createBonus();
                    }
                    diedEnemies++;
                }
           }
        }
    }
    if(!bullets.empty()&&!goodTanks.empty()) {
        for (auto obj1 : bullets) {
            for (auto obj2 : goodTanks) {
                if(bulletCollisionDetection(obj1, obj2)&&obj1->getBulletID()==1) {
                    obj1->destroy();
                    obj2->setHP(obj2->getHP()-1);
                    if(obj2->getHP()==-1)
                    {
                        obj2->destroy();
                    }
                    else
                    {
                        explosion = new Explosion((obj2->getX()+obj2->getWidth()),
                                                                  (obj2->getY()+obj2->getHeight()),CELL*2, CELL*2, new TankExplosion);
                                        explosions.push_back(explosion);
                        if(obj2->getID()==0)
                        {
                            obj2->setY(MYTANK_Y);
                            obj2->setX(MYTANK_X);
                        }
                        else
                        {
                            obj2->setX(MYFRIENDTANK_X);
                            obj2->setY(MYFRIENDTANK_Y);
                        }
                    }
                }
           }
        }
    }
    if(!bullets.empty()&&!bricks.empty()) {
        for (auto obj1 : bullets) {
            for (auto obj2 : bricks) {
                if(bulletCollisionDetection(obj1, obj2)) {
                    obj1->destroy();
                    obj2->getDamage(obj1->getDirection());
                }
           }
        }
    }
    if(!bullets.empty()) {
        for (auto obj1 : bullets) {
            for (auto obj2 : bullets) {
                if(obj1!=obj2&&bulletCollisionDetection(obj1, obj2)) {
                    obj1->destroy();
                    obj2->destroy();
                }
           }
        }
    }
    if(!bullets.empty()) {
            for (auto obj : bullets) {
                if(bulletCollisionDetection(obj, eagle)) {
                    obj->destroy();
                    eagle->destroy();

           }
        }
    }
}

bool Game::collisionDetection(Tank* tier, StaticObject* obj)
{
   auto rect1 = tier->boundRect();
   switch(tier->getDirection())
   {
   case MovingObject::Left:
       rect1.setX(rect1.x()-tier->getSpeed());
       break;
   case MovingObject::Right:
       rect1.setWidth(rect1.width()+tier->getSpeed());
       break;
   case MovingObject::Up:
       rect1.setY(rect1.y()-tier->getSpeed());
       break;
   case MovingObject::Down:
       rect1.setHeight(rect1.height()+tier->getSpeed());
       break;

   }
    auto rect2 = obj->boundRect();
    if(rect1.intersects(rect2))
        return true;
    else return false;
}

void Game::collisionCall()
{
    for(auto& tier : goodTanks)
    {
        for (auto& obj : bricks)
        {
            if(collisionDetection(tier,obj)){
                tier->setCanMove(false);
                tier->collisionReaction();
            }
        }
    }
    for(auto& tier : goodTanks)
    {
        if(bonus!=nullptr)
        {
            if(collisionDetection(tier,bonus)&&bonus->getType() == Bonus::Life)
            {
                delete bonus;
                bonus = nullptr;
                base->setProtection(true);
            }
            else if(collisionDetection(tier,bonus)&&bonus->getType() == Bonus::Bomb)
            {
                delete bonus;
                bonus = nullptr;
                for (auto obj2 : enemies) {
                    obj2->destroy();
                    diedEnemies++;
               }
            }
        }
    }
    for(auto& tier : enemies)
    {
        for (auto& obj : bricks)
        {
            if(collisionDetection(tier,obj)){
                tier->collisionReaction();
                tier->setCanMove(false);

            }

        }
    }
    for(auto& tier : goodTanks)
    {
        for (auto& obj : enemies)
        {
            if(collisionDetection(tier,obj)){
                tier->collisionReaction();
                tier->setCanMove(false);
            }

        }
    }
    for(auto& tier : goodTanks)
    {
        for (auto& obj : goodTanks)
        {
            if(tier!=obj&&collisionDetection(tier,obj)){
                tier->collisionReaction();
                tier->setCanMove(false);
            }

        }
    }
    for(auto& tier : enemies)
    {
        for (auto& obj : goodTanks)
        {
            if(collisionDetection(tier,obj)){
                tier->collisionReaction();
                tier->setCanMove(false);
            }

        }
    }
    for(auto& tier : enemies)
    {
        for (auto& obj : enemies)
        {
            if(tier!=obj&&collisionDetection(tier,obj)){

                //tier->collisionReaction();
                //tier->setCanMove(false);
                tier->reverseDirection(tier->getDirection());
            }
        }
    }
}

void Game::createShoot()
{
    if(!goodTanks.empty())
    {
        for (auto tier : goodTanks)
        {
            if(tier->getCanShoot())
            {
                Bullet* b = tier->shoot();
                if(b!=nullptr)
                {
                    bullets.push_back(b);
                    tier->setCanShoot(false);
                    b->setOwner(tier);
                }
            }
        }
    }
    if(!enemies.empty())
    {
        for (auto tier : enemies)
        {
            if(tier->getCanShoot())
            {
                Bullet* b = tier->shoot();
                if(b!=nullptr)
                {
                    bullets.push_back(b);
                    tier->setCanShoot(false);
                    b->setOwner(tier);
                }
            }
        }
    }
}

void Game::moveShoot()
{
    if(!bullets.empty()) {
        for (auto obj : bullets) {
               obj->moveBullet(obj->getDirection());
       }
    }
}

void Game::deleteDiedObjects()
{

    if(!bullets.empty()) {
        for (std::vector<Bullet*>::iterator obj = bullets.begin(); obj < bullets.end(); obj++) {
            if((*obj)->isDestroyed()) {
                (*obj)->getOwner()->setCanShoot(true);
                delete *obj;
               bullets.erase(obj);
            }
       }
    }
    if(!bricks.empty()) {
        for (std::vector<Brick*>::iterator obj = bricks.begin(); obj< bricks.end();obj++) {
            if((*obj)->isDestroyed()) {
                delete *obj;
               bricks.erase(obj);
            }
       }
    }
    if(!signs.empty()) {
        for (std::vector<EnemySign*>::iterator obj = signs.begin(); obj< signs.end();obj++) {
            if((*obj)->isDestroyed()) {
                delete *obj;
               signs.erase(obj);
            }
       }
    }
    if(!enemies.empty()) {
        for (std::vector<BadTank*>::iterator obj = enemies.begin(); obj < enemies.end(); obj++) {
            if((*obj)->isDestroyed()) {
                if((*obj)->getTypeID()==0)
                {
                   simpleKilled++;
                }
                else if((*obj)->getTypeID()==1)
                {
                    speedyKilled++;
                }
                enemyCounter--;
                delete *obj;
                enemies.erase(obj);
            }
       }
    }
    if(!goodTanks.empty()) {
        for (std::vector<GoodTank*>::iterator obj = goodTanks.begin(); obj < goodTanks.end(); obj++) {
            if((*obj)->isDestroyed()) {
                delete *obj;
                goodTanks.erase(obj);
            }
       }
    }
    if(!explosions.empty()) {
        for (std::vector<StaticObject*>::iterator obj = explosions.begin(); obj< explosions.end();obj++) {
            if((*obj)->isDestroyed()) {
                delete *obj;
               explosions.erase(obj);
            }
       }
    }
    if(bonus!=nullptr&&bonus->isDestroyed())
    {
        delete bonus;

    }
}

void Game::readGame()
{
    QFile file(level->getMapFile());
    if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
        int y = 0;
        while (!file.atEnd()) {
            QByteArray arr = file.readLine();
            for(int x = 0; x <= arr.size(); x++) {
                 if(arr[x] == '#')
                 {
                    brick = new Brick(x*CELL/2,y*CELL/2);
                    bricks.push_back(brick);
                 }
                    else if(arr[x] == '%')
                    {
                       steelBrick = new SteelBrick(x*CELL/2,y*CELL/2);
                       bricks.push_back(steelBrick);
                    }
            }
            y++;
        }
    }
    file.close();
}

void Game::readTankOfLevel()
{
    QFile file(level->getTankFile());
    if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QString text = file.readAll();
        strcpy(tankArray,text.toLocal8Bit().data());
        file.close();
    }
}

void Game::drawGame(QPainter *painter)
{
    for (auto& obj : bricks)
    {
        if(obj!=nullptr)
        obj->draw(painter);
    }
    if(!bullets.empty()){
        for(auto obj : bullets) {
            obj->draw(painter);
        }
    }
    if(!signs.empty()){
        for(auto obj : signs) {
            obj->draw(painter);
        }
    }
    if(!enemies.empty()){
        for(auto obj : enemies) {
            obj->draw(painter);
        }
    }
    if(!goodTanks.empty()){
        for(auto obj : goodTanks) {
            obj->draw(painter);
        }
    }
    if(!explosions.empty()){
        for(auto obj : explosions) {
            obj->draw(painter);
        }
    }
    lifeScore->draw(painter,tank->getHP());
    if(bonus!=nullptr)
    {
        bonus->draw(painter);
    }
    level->draw(painter);
    eagle->draw(painter);
        if(gameOverLabel!=nullptr)
    {
        gameOverLabel->draw(painter);
    }
}

void Game::reactionToKeyPress(QKeyEvent *event)
{
    if(!goodTanks.empty()){
        for (auto obj : goodTanks) {
              obj->keyMoving(event);
        }
    }
}

void Game::reactionToKeyRelease(QKeyEvent *event)
{
    if(!goodTanks.empty()){
        for (auto obj : goodTanks) {
              obj->keyReleasing(event);
        }
    }
}
