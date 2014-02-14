#ifndef ZEROSENDER_H
#define ZEROSENDER_H

#include <QString>

class ZeroSender
{
private:
    void *context;
public:
    ZeroSender();
    void send(QString topic, QString message);
};

#endif // ZEROSENDER_H
