#include <QtGui/QGuiApplication>
#include <QtQuick>
#include "qtquick2applicationviewer.h"

#include "zerospeaker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ZeroSpeaker>("ZeroSpeaker", 1, 0, "ZeroSpeaker");

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/hellozmq/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
