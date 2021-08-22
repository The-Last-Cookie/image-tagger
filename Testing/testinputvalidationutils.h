#pragma once

#include <QTest>
#include <QString>
#include <QObject>

#include "Utils/inputvalidationutils.h"

class TestInputValidationUtils : public QObject
{
    Q_OBJECT

    private slots:
        void testStringValidation();
};
