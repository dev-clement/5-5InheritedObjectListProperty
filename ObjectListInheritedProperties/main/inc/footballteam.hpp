#ifndef FOOTBALLTEAM_HPP
#define FOOTBALLTEAM_HPP

#include <QVector>
#include <QObject>
#include <QQmlEngine>
#include <QQmlListProperty>
#include "player.hpp"

class FootBallTeam : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coach READ coach WRITE setCoach NOTIFY coachChanged)
    Q_PROPERTY(Player *captain READ captain WRITE setCaptain NOTIFY captainChanged)
    Q_PROPERTY(QQmlListProperty<Player> players READ players NOTIFY playersChanged)
public:
    explicit FootBallTeam(QObject *po_po_player = nullptr);
    QString title() const;
    QString coach() const;
    Player *captain() const;

    void setTitle(const QString &o_title);
    void setCoach(const QString &o_coach);
    void setCaptain(Player *po_captain);
    QQmlListProperty<Player> players();

    // Helpers method
    void appendPlayerCustom(Player *po_player);
    int playerCountCustom() const;
    Player *playerCustom(int i_idx) const;
    void clearPlayerCustom();

signals:
    void titleChanged(const QString &o_title);
    void coachChanged(const QString &o_coach);
    void captainChanged(Player *po_captain);
    void playersChanged();

private:
    // Callbacks methods
    static void appendPlayer(QQmlListProperty<Player> *po_players, Player *po_player);
    static qsizetype playerCount(QQmlListProperty<Player> *po_players);
    static Player *player(QQmlListProperty<Player> *po_players, qsizetype i_playerIdx);
    static void clearPlayers(QQmlListProperty<Player> *po_players);

private:
    QString             _o_title;
    QString             _o_coach;
    Player              *_po_captain = nullptr;
    QVector<Player *>   _o_players;
};

#endif // FOOTBALLTEAM_HPP
