#include "player.hpp"

Player::Player(QObject *po_po_player)
    : QObject{po_po_player} {}

QString Player::name() const {
    return _o_name;
}

void Player::setName(const QString &o_name) {
    if (_o_name == o_name)
        return;
    _o_name = o_name;
    emit nameChanged(_o_name);
}

bool Player::isPlaying() const {
    return _b_isPlaying;
}

void Player::setPlaying(bool b_isPlaying) {
    if (_b_isPlaying == b_isPlaying)
        return;
    _b_isPlaying = b_isPlaying;
    emit playingChanged(_b_isPlaying);
}

QString Player::position() const {
    return _o_position;
}

void Player::setPosition(const QString &o_position) {
    if (_o_position == o_position)
        return;
    _o_position = o_position;
    emit positionChanged(_o_position);
}
