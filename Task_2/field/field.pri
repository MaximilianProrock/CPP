!FIELD_PRI {

CONFIG += FIELD_PRI

INCLUDEPATH += $$PWD

include(point/point.pri)
HEADERS += \
    $$PWD/field.h

SOURCES += \
    $$PWD/field.cpp

}

HEADERS += \
    $$PWD/fieldexception.h

SOURCES += \
    $$PWD/fieldexception.cpp