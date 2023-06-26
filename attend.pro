QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    pass.cpp \
    stud.cpp \
    student.cpp \
    tea.cpp \
    teacher.cpp

HEADERS += \
    mainwindow.h \
    pass.h \
    person.h \
    stud.h \
    student.h \
    tea.h \
    teacher.h

FORMS += \
    mainwindow.ui \
    pass.ui \
    student.ui \
    teacher.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    att_SYS.sql \
    ujs.png

RESOURCES += \
    res.qrc
