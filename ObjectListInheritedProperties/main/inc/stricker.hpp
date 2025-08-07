#ifndef STRICKER_HPP
#define STRICKER_HPP

#include <QtQml>
#include <QObject>
#include "player.hpp"

class Stricker : public Player {
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Stricker(QObject *po_player = nullptr);

    void play() override;

    void strike();

signals:
};

#endif // STRICKER_HPP
