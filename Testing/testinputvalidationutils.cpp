#include "testinputvalidationutils.h"

void TestInputValidationUtils::testStringValidation()
{
    QVERIFY(InputValidationUtils::isValidString(" ") == false);
}

QTEST_APPLESS_MAIN(TestInputValidationUtils)
#include "testinputvalidationutils.moc"
