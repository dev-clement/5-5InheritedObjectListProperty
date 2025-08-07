#include <QDebug>
#include "defender.hpp"

Defender::Defender(QObject *po_parent)
    : Player{po_parent} {}

void Defender::play() {
    qDebug() << "Before defending, let's do some magic !";
    defend();
}

void Defender::defend() {
    qDebug() << "Defending our side !!";
}
