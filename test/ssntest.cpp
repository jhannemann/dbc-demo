// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <QTest>
#include "../ssn/ssn.h"
#include <assertexcept.h>

Q_DECLARE_METATYPE(std::string)

class SSNTest : public QObject {
Q_OBJECT
private slots:

    void constructor_data() {
        QTest::addColumn<std::string>("ssn");
        QTest::newRow("random") << std::string("123456789");
        QTest::newRow("min") << std::string("001010001");
        QTest::newRow("max") << std::string("899999999");
        QTest::newRow("equal") << std::string("111111111");
        QTest::newRow("min group") << std::string("001456789");
        QTest::newRow("max group") << std::string("899456789");
        QTest::newRow("min area") << std::string("123016789");
        QTest::newRow("max area") << std::string("123996789");
        QTest::newRow("min serial") << std::string("123450001");
        QTest::newRow("max serial") << std::string("123459999");
        QTest::newRow("random dash") << std::string("123-45-6789");
        QTest::newRow("min dash") << std::string("001-01-0001");
        QTest::newRow("max dash") << std::string("899-99-9999");
        QTest::newRow("equal dash") << std::string("111-11-1111");
        QTest::newRow("min group dash") << std::string("001-45-6789");
        QTest::newRow("max group dash") << std::string("899-45-6789");
        QTest::newRow("min area dash") << std::string("123-01-6789");
        QTest::newRow("max area dash") << std::string("123-99-6789");
        QTest::newRow("min serial dash") << std::string("123-45-0001");
        QTest::newRow("max serial dash") << std::string("123-45-9999");
        QTest::newRow("min space") << std::string("001 01 0001");
        QTest::newRow("max space") << std::string("899 99 9999");
        QTest::newRow("random space") << std::string("123 45 6789");
        QTest::newRow("equal space") << std::string("111 11 1111");
        QTest::newRow("min group space") << std::string("001 45 6789");
        QTest::newRow("max group space") << std::string("899 45 6789");
        QTest::newRow("min area space") << std::string("123 01 6789");
        QTest::newRow("max area space") << std::string("123 99 6789");
        QTest::newRow("min serial space") << std::string("123 45 0001");
        QTest::newRow("max serial space") << std::string("123 45 9999");
    }

    void constructor() {
        QFETCH(std::string, ssn);
        SSN s(ssn);
    }

    void constructor_xfail_data() {
        QTest::addColumn<std::string>("ssn");
        QTest::newRow("empty") << std::string("");
        QTest::newRow("letters") << std::string("abc-de-fghi");
        QTest::newRow("short area") << std::string("23-45-6789");
        QTest::newRow("zero area") << std::string("000-45-6789");
        QTest::newRow("sixes area") << std::string("666-45-6789");
        QTest::newRow("letters area") << std::string("abc-45-6789");
        QTest::newRow("zero group") << std::string("123-00-6789");
        QTest::newRow("short group") << std::string("123-4-6789");
        QTest::newRow("letters group") << std::string("123-ef-6789");
        QTest::newRow("zero serial") << std::string("123-45-0000");
        QTest::newRow("short serial") << std::string("123-45-678");
        QTest::newRow("letters serial") << std::string("123-45-ghij");
        QTest::newRow("ITIN 1") << std::string("900-45-6789");
        QTest::newRow("ITIN 2") << std::string("990-45-6789");
        QTest::newRow("ITIN 3") << std::string("999-45-6789");
        QTest::newRow("Mixed separators 1") << std::string("123 45-6789");
        QTest::newRow("Mixed separators 2") << std::string("123-45 6789");
        QTest::newRow("Mixed separators 3") << std::string("12345-6789");
        QTest::newRow("Mixed separators 4") << std::string("123-456789");
        QTest::newRow("Mixed separators 5") << std::string("12345 6789");
        QTest::newRow("Mixed separators 6") << std::string("123 456789");
    }

    void constructor_xfail() {
        QFETCH(std::string, ssn);
#ifdef NDEBUG
        // the second argument is to suppress a warning about variadic
        // macro arguments needing at least one argument
        QSKIP("Assertions disabled", "");
#endif
        QVERIFY_THROWS_EXCEPTION(AssertException, SSN s(ssn));
    }

    void str_data() {
        QTest::addColumn<std::string>("ssn");
        QTest::addColumn<std::string>("result");
        QTest::newRow("No separator") << std::string("123456789")
                                      << std::string("123-45-6789");
        QTest::newRow("Dash separator") << std::string("123-45-6789")
                                        << std::string("123-45-6789");
        QTest::newRow("Space separator") << std::string("123 45 6789")
                                         << std::string("123-45-6789");
    }

    void str() {
        QFETCH(std::string, ssn);
        QFETCH(std::string, result);
        SSN s(ssn);
        QCOMPARE(s.str(), result);
    }

    void equality_operator_data() {
        QTest::addColumn<std::string>("ssn1");
        QTest::addColumn<std::string>("ssn2");
        QTest::addColumn<bool>("result");
        QTest::newRow("Same format") << std::string("123-45-6789")
                                     << std::string("123-45-6789")
                                     << true;
        QTest::newRow("Different format") << std::string("123-45-6789")
                                          << std::string("123456789")
                                          << true;
        QTest::newRow("Different area") << std::string("123-45-6789")
                                        << std::string("023-45-6789")
                                        << false;
        QTest::newRow("Different group") << std::string("123-45-6789")
                                         << std::string("123-46-6789")
                                         << false;
        QTest::newRow("Different serial") << std::string("123-45-6789")
                                          << std::string("123-46-6780")
                                          << false;
    }

    void equality_operator() {
        QFETCH(std::string, ssn1);
        QFETCH(std::string, ssn2);
        QFETCH(bool, result);
        SSN s1(ssn1);
        SSN s2(ssn2);
        QCOMPARE(s1==s2, result);
    }
};

QTEST_MAIN(SSNTest)
#include "ssntest.moc"
