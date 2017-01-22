#include "zerosender.h"

#include <QDebug>

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

ZeroSender::ZeroSender()
{
    this->context = zmq_ctx_new ();
}

void ZeroSender::send(QString topic, QString msg)
{
    // Converting topic and msg to a single binary payload for ZMQ:
    QString payload_str = topic + " " + msg;
    QByteArray payload = payload_str.toLocal8Bit();
    qDebug() << "payload " << payload << "\n";

    qInfo() << "Connecting to the Intercom broker...";
    void *requester = zmq_socket (this->context, ZMQ_REQ);
    zmq_connect(requester, "tcp://spirit:5556");
    zmq_send(requester, payload.data(), payload.length(), 0);

    char buffer [4];
    zmq_recv (requester, buffer, 4, 0);
    buffer[3] = '\0';
    qDebug() << "Received response [" << buffer << "]";
}
