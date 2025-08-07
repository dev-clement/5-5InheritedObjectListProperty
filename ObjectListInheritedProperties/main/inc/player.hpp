#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QObject>
#include <QQmlEngine>

class Player : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString position READ position WRITE setPosition NOTIFY positionChanged)
public:
    explicit Player(QObject *po_po_player = nullptr);
    QString name() const;
    void setName(const QString &o_Name);
    bool isPlaying() const;
    void setPlaying(bool b_isPlaying);
    QString position() const;
    void setPosition(const QString &o_Position);

    Q_INVOKABLE virtual void play() = 0;

signals:
    void nameChanged(const QString &o_name);
    void playingChanged(bool b_isPlaying);
    void positionChanged(const QString &o_position);

private:
    QString _o_name;
    bool _b_isPlaying;
    QString _o_position;
};

#endif // PLAYER_HPP
