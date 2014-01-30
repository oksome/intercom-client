#ifndef ZEROSPEAKER_H
#define ZEROSPEAKER_H

#include <QObject>
#include <QDebug>

class ZeroSpeaker : public QObject
{
    Q_OBJECT
public:
    explicit ZeroSpeaker(QObject *parent = 0);
    Q_INVOKABLE void printMessage(QString txt);
    Q_INVOKABLE void playMPD();
    Q_INVOKABLE void pauseMPD();
signals:

public slots:

};

#endif // ZEROSPEAKER_H
