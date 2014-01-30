#include "zerospeaker.h"

ZeroSpeaker::ZeroSpeaker(QObject *parent) :
    QObject(parent)
{
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
    printf ("Connecting to hello world server...\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:mpd.play {}", 14, 0);

    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"00100\", \"action\": \"on\", \"group\": \"00001\"}", 69, 0);

    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"10000\", \"action\": \"on\", \"group\": \"00001\"}", 69, 0);

    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"00010\", \"action\": \"on\", \"group\": \"00001\"}", 69, 0);

    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"01000\", \"action\": \"on\", \"group\": \"00001\"}", 69, 0);

    char buffer [4];
    zmq_recv (requester, buffer, 4, 0);
    buffer[3] = '\0';
    qDebug() << "Received response [" << buffer << "]";
}

void ZeroSpeaker::pauseMPD()
{
    printf ("Connecting to hello world server...\n");

    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:mpd.pause {}", 15, 0);

    context = zmq_ctx_new ();
    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"00100\", \"action\": \"off\", \"group\": \"00001\"}", 70, 0);

    context = zmq_ctx_new ();
    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"10000\", \"action\": \"off\", \"group\": \"00001\"}", 70, 0);

    context = zmq_ctx_new ();
    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"00010\", \"action\": \"off\", \"group\": \"00001\"}", 70, 0);

    context = zmq_ctx_new ();
    requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://intercom:5556");
    zmq_send(requester, "do:arduino.switch {\"plug\": \"01000\", \"action\": \"off\", \"group\": \"00001\"}", 70, 0);

    char buffer [4];
    zmq_recv (requester, buffer, 4, 0);
    buffer[3] = '\0';
    qDebug() << "Received response [" << buffer << "]";
}
