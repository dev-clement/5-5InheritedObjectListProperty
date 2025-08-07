#include <QDebug>
#include "stricker.hpp"

Stricker::Stricker(QObject *po_player)
    : Player{po_player} {}

void Stricker::play() {
    qDebug() << "Before striking the ball, let's explain";
    strike();
}

void Stricker::strike() {
    qDebug() << "Strike the ball";
}
