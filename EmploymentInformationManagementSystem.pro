#-------------------------------------------------
#
# Project created by QtCreator 2020-03-25T11:22:42
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmploymentInformationManagementSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        UserSelectionDialog.cpp \
    StudentLoginDialog.cpp \
    TeacherLoginDialog.cpp \
    EnterpriseLoginDialog.cpp \
    AdminLoginDialog.cpp \
    StudentMainWindow.cpp \
    TeacherMainWindow.cpp \
    EnterpriseMainWindow.cpp \
    AdminMainWindow.cpp \
    DeleteDialog.cpp \
    SendResumeDialog.cpp \
    SpeakDialog.cpp \
    AllUse.cpp

HEADERS += \
        UserSelectionDialog.h \
    StudentLoginDialog.h \
    TeacherLoginDialog.h \
    EnterpriseLoginDialog.h \
    AdminLoginDialog.h \
    StudentMainWindow.h \
    TeacherMainWindow.h \
    EnterpriseMainWindow.h \
    AdminMainWindow.h \
    DeleteDialog.h \
    SendResumeDialog.h \
    SpeakDialog.h \
    AllUse.h

FORMS += \
        UserSelectionDialog.ui \
    StudentLoginDialog.ui \
    TeacherLoginDialog.ui \
    EnterpriseLoginDialog.ui \
    AdminLoginDialog.ui \
    StudentMainWindow.ui \
    TeacherMainWindow.ui \
    EnterpriseMainWindow.ui \
    AdminMainWindow.ui \
    DeleteDialog.ui \
    SendResumeDialog.ui \
    SpeakDialog.ui

RESOURCES += \
    pic.qrc
