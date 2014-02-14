#ifndef ZEROSPEAKER_H
#define ZEROSPEAKER_H

#include <QObject>
#include <QDebug>

#include "zerosender.h"

class ZeroSpeaker : public QObject
{
    Q_OBJECT
private:
    ZeroSender sender;
public:
    explicit ZeroSpeaker(QObject *parent = 0);
    Q_INVOKABLE void printMessage(QString txt);
    Q_INVOKABLE void playMPD();
    Q_INVOKABLE void pauseMPD();
signals:

public slots:

};

#endif // ZEROSPEAKER_H
