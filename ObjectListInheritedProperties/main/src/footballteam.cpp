#include <QDebug>
#include "footballteam.hpp"

FootBallTeam::FootBallTeam(QObject *po_player)
    : QObject{po_player}
{}

QString FootBallTeam::title() const {
    return _o_title;
}

QString FootBallTeam::coach() const {
    return _o_coach;
}

Player *FootBallTeam::captain() const {
    return _po_captain;
}

void FootBallTeam::setTitle(const QString &o_title) {
    if (_o_title == o_title)
        return;
    _o_title = o_title;
    emit titleChanged(_o_title);
}

void FootBallTeam::setCoach(const QString &o_coach) {
    if (_o_coach == o_coach)
        return;
    _o_coach = o_coach;
    emit coachChanged(o_coach);
}

void FootBallTeam::setCaptain(Player *po_captain) {
    if (_po_captain == po_captain)
        return;
    _po_captain = po_captain;
    emit captainChanged(_po_captain);
}

QQmlListProperty<Player> FootBallTeam::players() {
    return QQmlListProperty<Player>(this, this
                                    , &FootBallTeam::appendPlayer
                                    , &FootBallTeam::playerCount
                                    , &FootBallTeam::player
                                    , &FootBallTeam::clearPlayers);
}

void FootBallTeam::appendPlayerCustom(Player *po_player) {
    qDebug() << "Adding player to vector: " << po_player->name();
    _o_players.append(po_player);
}

int FootBallTeam::playerCountCustom() const {
    return _o_players.count();
}

Player *FootBallTeam::playerCustom(int i_idx) const {
    return _o_players.at(i_idx);
}

void FootBallTeam::clearPlayerCustom() {
    _o_players.clear();
}

void FootBallTeam::appendPlayer(QQmlListProperty<Player> *po_players, Player *po_player) {
    reinterpret_cast<FootBallTeam *>(po_players->data)->appendPlayerCustom(po_player);
}

qsizetype FootBallTeam::playerCount(QQmlListProperty<Player> *po_players) {
    return reinterpret_cast<FootBallTeam *>(po_players->data)->playerCountCustom();
}

Player *FootBallTeam::player(QQmlListProperty<Player> *po_players, qsizetype i_playerIdx) {
    return reinterpret_cast<FootBallTeam *>(po_players->data)->playerCustom(i_playerIdx);
}

void FootBallTeam::clearPlayers(QQmlListProperty<Player> *po_players) {
    reinterpret_cast<FootBallTeam *>(po_players->data)->clearPlayerCustom();
}







