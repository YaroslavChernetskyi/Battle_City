#include "scoretable.h"
#include "QDebug"

ScoreTable::ScoreTable()
{
}

void ScoreTable::drawBackground(QPainter *painter)
{
    QPixmap pixmap("://score.png");
    painter->drawPixmap(0, 0, (WIDTH+2)*CELL, HEIGHT*CELL, pixmap);
}

void ScoreTable::drawPoints(QPainter *painter, std::array<int, 4> scoreArray)
{
    int simpleCount = scoreArray[0];
    int speedyCount = scoreArray[1];
    int simplePoints = scoreArray[2];
    int speedyPoints = scoreArray[3];
    int score = simpleCount*simplePoints+speedyCount*speedyPoints;
    int simpleTotal = simpleCount*simplePoints;
    int speedyTotal = speedyCount*speedyPoints;
    int totalCount = speedyCount+simpleCount;
    int x_count = 225;
    int x_points = 125;
    int y_simple = 167;
    int y_speedy = 208;
    int numSize = 13;
    int y_score = 130;
    int x_score =180;
    int x_total = 235;
    int y_total = 320;
    auto b = std::to_string(score);
    for(unsigned int i =0; i<b.size(); i++)
    {
        QPixmap pixmap(numbersToPic(b[i]));
        painter->drawPixmap(x_score-static_cast<int>(b.size()-i)*20, y_score, numSize, numSize, pixmap);
    }
    auto simple_count = std::to_string(simpleCount);
    for(unsigned int i =0; i<simple_count.size(); i++)
    {
        QPixmap pixmap(numbersToPic(simple_count[i]));
        painter->drawPixmap(x_count-static_cast<int>(simple_count.size()-i)*20, y_simple, numSize, numSize, pixmap);
    }
    auto speedy_count = std::to_string(speedyCount);
    for(unsigned int i =0; i<speedy_count.size(); i++)
    {
        QPixmap pixmap(numbersToPic(speedy_count[i]));
        painter->drawPixmap(x_count-static_cast<int>(speedy_count.size()-i)*20, y_speedy, numSize, numSize, pixmap);
    }
    auto total = std::to_string(totalCount);
    for(unsigned int i =0; i<total.size(); i++)
    {
        QPixmap pixmap(numbersToPic(total[i]));
        painter->drawPixmap(x_total-static_cast<int>(total.size()-i)*20, y_total, numSize, numSize, pixmap);
    }
    auto simple_points = std::to_string(simpleTotal);
    for(unsigned int i =0; i<simple_points.size(); i++)
    {
        QPixmap pixmap(numbersToPic(simple_points[i]));
        painter->drawPixmap(x_points-static_cast<int>(simple_points.size()-i)*20, y_simple, numSize, numSize, pixmap);
    }
    auto speedy_points = std::to_string(speedyTotal);
    for(unsigned int i =0; i<speedy_points.size(); i++)
    {
        QPixmap pixmap(numbersToPic(speedy_points[i]));
        painter->drawPixmap(x_points-static_cast<int>(speedy_points.size()-i)*20, y_speedy, numSize, numSize, pixmap);
    }

}

QString ScoreTable::numbersToPic(char num)
{
    switch (num) {
    case '0':
        return "://0_w.png";
        break;
    case '1':
        return"://1_w.png";
        break;
    case '2':
        return "://2_w.png";
        break;
    case '3':
        return "://3_w.png";
        break;
    case '4':
        return "://4_w.png";
        break;
    case '5':
        return "://5_w.png";
        break;
    case '6':
        return "://6_w.png";
        break;
    case '7':
        return "://7_w.png";
        break;
    case '8':
        return "://8_w.png";
        break;
    case '9':
        return "://9_w.png";
        break;
    }
    return "";
}
