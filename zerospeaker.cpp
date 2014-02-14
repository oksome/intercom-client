#include "zerospeaker.h"
#include "zerosender.h"

ZeroSpeaker::ZeroSpeaker(QObject *parent) :
    QObject(parent)
{
    this->sender = ZeroSender();
}

void ZeroSpeaker::printMessage(QString txt)
{
    qDebug() << "Message from QML: " << txt;
}

/* ZMQ Part */

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


void ZeroSpeaker::playMPD()
{
    this->sender.send(QString("do:mpd.play"), QString("{}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"10000\", \"action\": \"on\", \"group\": \"00001\"}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"00010\", \"action\": \"on\", \"group\": \"00001\"}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"01000\", \"action\": \"on\", \"group\": \"00001\"}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"00100\", \"action\": \"on\", \"group\": \"00001\"}"));
}

void ZeroSpeaker::pauseMPD()
{
    this->sender.send(QString("do:mpd.pause"), QString("{}"));

    this->sender.send(QString("do:pc.suspend"), QString("{}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"10000\", \"action\": \"off\", \"group\": \"00001\"}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"00010\", \"action\": \"off\", \"group\": \"00001\"}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"00100\", \"action\": \"off\", \"group\": \"00001\"}"));

    this->sender.send(QString("do:arduino.switch"),
                      QString("{\"plug\": \"01000\", \"action\": \"off\", \"group\": \"00001\"}"));
}


