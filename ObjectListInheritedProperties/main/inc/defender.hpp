#ifndef DEFENDER_HPP
#define DEFENDER_HPP

#include <QtQml>
#include "player.hpp"

class Defender : public Player {
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Defender(QObject *po_parent = nullptr);

    void play() override;
    void defend();
signals:
};

#endif // DEFENDER_HPP
