TEMPLATE = app

QT += core gui opengl
CONFIG += c++11 opengl

SOURCES += main.cpp \
    gldisplay.cpp \
    mainwindow.cpp \
    mesh.cpp \
    perlin.cpp \
    perlinuni.cpp \
    point.cpp \
    pointcirculator.cpp \
    pointiterator.cpp \
    terrain.cpp \
    triangle.cpp \
    trianglecirculator.cpp \
    triangleiterator.cpp \
    turbulence.cpp \
    vector3d.cpp \
    soil.cpp \
    flowmap.cpp \
    ecosystem.cpp \
    tree.cpp

LIBS += -lopengl32

RESOURCES += \
    rsc.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui

DISTFILES +=

HEADERS += \
    gldisplay.h \
    mainwindow.h \
    mesh.h \
    perlin.h \
    perlinuni.h \
    point.h \
    pointcirculator.h \
    pointiterator.h \
    terrain.h \
    triangle.h \
    trianglecirculator.h \
    triangleiterator.h \
    turbulence.h \
    vector3d.h \
    soil.h \
    flowmap.h \
    ecosystem.h \
    tree.h
