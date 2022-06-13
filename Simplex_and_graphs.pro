QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fractions.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    modelstorage.cpp \
    pointgraph.cpp \
    qcustomplot.cpp \
    referencegraph.cpp \
    referencesimplex.cpp \
    simplex.cpp \
    unused_methods.cpp

HEADERS += \
    fractions.h \
    graph.h \
    mainwindow.h \
    modelstorage.h \
    pointgraph.h \
    qcustomplot.h \
    referencegraph.h \
    referencesimplex.h \
    simplex.h

FORMS += \
    mainwindow.ui \
    referencegraph.ui \
    referencesimplex.ui

# Default rules for deployment.
win32: RC_ICONS = simplex.ico
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
