#ifndef SCORETABLE_H
#define SCORETABLE_H

#include "QPainter"
#include "staticobject.h"

class ScoreTable
{
    int counter{0};
public:
    ScoreTable();
    ~ScoreTable() = default;
    void drawBackground(QPainter* painter);
    QString numbersToPic(char);
    void drawPoints(QPainter *painter, std::array<int, 4>);
};

#endif // SCORETABLE_H
