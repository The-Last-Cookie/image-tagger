QT += \
    quick \
    sql

CONFIG += \
    c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AccountManagement/accesscontrolsystem.cpp \
        AccountManagement/passwordmanager.cpp \
        AccountManagement/session.cpp \
        AccountManagement/user.cpp \
        AccountManagement/usermanager.cpp \
        DataManagement/Author/authormanager.cpp \
        DataManagement/Author/basicauthor.cpp \
        DataManagement/File/basicfile.cpp \
        DataManagement/File/filemanager.cpp \
        DataManagement/Group/basicgroup.cpp \
        DataManagement/Group/groupmanager.cpp \
        DataManagement/Search/querycreationutils.cpp \
        DataManagement/Search/searchmanager.cpp \
        DataManagement/Search/searchresult.cpp \
        DataManagement/Search/searchutils.cpp \
        DataManagement/Tag/basictag.cpp \
        DataManagement/Tag/tagmanager.cpp \
        StringCalc/binary.cpp \
        StringCalc/converter.cpp \
        StringCalc/decimal.cpp \
        StringCalc/hexadecimal.cpp \
        StringCalc/stringcalc.cpp \
        Utils/dateutils.cpp \
        Utils/inputvalidationutils.cpp \
        databasemanager.cpp \
        logger.cpp \
        main.cpp \
        settingsmanager.cpp

HEADERS += \
    AccountManagement/accesscontrolsystem.h \
    AccountManagement/passwordmanager.h \
    AccountManagement/session.h \
    AccountManagement/user.h \
    AccountManagement/usermanager.h \
    DataManagement/Author/authormanager.h \
    DataManagement/Author/basicauthor.h \
    DataManagement/File/basicfile.h \
    DataManagement/File/filemanager.h \
    DataManagement/Group/basicgroup.h \
    DataManagement/Group/groupmanager.h \
    DataManagement/Search/querycreationutils.h \
    DataManagement/Search/searchmanager.h \
    DataManagement/Search/searchresult.h \
    DataManagement/Search/searchutils.h \
    DataManagement/Tag/basictag.h \
    DataManagement/Tag/tagmanager.h \
    StringCalc/converter.h \
    StringCalc/stringcalc.h \
    Utils/dateutils.h \
    Utils/inputvalidationutils.h \
    databasemanager.h \
    logger.h \
    settingsmanager.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    StringCalc/LICENCE.md \
    StringCalc/README.md
