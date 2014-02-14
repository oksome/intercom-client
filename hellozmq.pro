# Add more folders to ship with the application, here
folder_01.source = qml/hellozmq
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    zerospeaker.cpp \
    zerothread.cpp \
    zerosender.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    zerospeaker.h \
    zerothread.h \
    zerosender.h

# ZeroMQ
macx {
    LIBS += -L/usr/local/Cellar/zeromq/3.2.4/lib/ -lzmq

    INCLUDEPATH += /usr/local/Cellar/zeromq/3.2.4/include
    DEPENDPATH += /usr/local/Cellar/zeromq/3.2.4/include

    PRE_TARGETDEPS += /usr/local/Cellar/zeromq/3.2.4/lib/libzmq.a
}

# ZeroMQ ARM
android {
    LIBS += -L$$PWD/zeromq-android/lib/ -lzmq

    INCLUDEPATH += $$PWD/zeromq-android/include
    DEPENDPATH += $$PWD/zeromq-android/include

    PRE_TARGETDEPS += $$PWD/zeromq-android/lib/libzmq.la
}

OTHER_FILES +=
