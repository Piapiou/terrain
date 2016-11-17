TEMPLATE = app

QT += core gui opengl
CONFIG += c++11 opengl

SOURCES += main.cpp \
    mesh.cpp \
    perlin.cpp \
    perlinuni.cpp \
    point.cpp \
    terrain.cpp \
    triangle.cpp \
    turbulence.cpp \
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

DISTFILES +=

HEADERS += \
    mesh.h \
    perlin.h \
    perlinuni.h \
    point.h \
    terrain.h \
    triangle.h \
    turbulence.h \
    soil.h \
    flowmap.h \
    ecosystem.h \
    tree.h
