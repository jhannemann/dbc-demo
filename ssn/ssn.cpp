// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "ssn.h"

#include <assertexcept.h>
#include <cassert>

const std::regex SSN::inputRegex() {
    return std::regex
            ("^(?!000)(?!666)(?!9)\\d{3}([- ]?)(?!00)\\d{2}\\1(?!0000)\\d{4}$");
}

const std::regex SSN::outputRegex() {
    return std::regex
            ("^(?!000)(?!666)(?!9)\\d{3}-(?!00)\\d{2}-(?!0000)\\d{4}$");
}

SSN::SSN(const std::string& ssn) {
    // preconditions
    BOOST_ASSERT_MSG(std::regex_match(ssn, inputRegex()),
                     "Valid SSN constructor argument");
    BOOST_ASSERT_MSG(ssn.size() == 9 || ssn.size() == 11,
                     "SSN has the right size");
    if (ssn.size() == 11) {
        m_area = ssn.substr(0, 3);
        m_group = ssn.substr(4, 2);
        m_serial = ssn.substr(7, 4);
    } else {
        assert(ssn.size() == 9);
        m_area = ssn.substr(0, 3);
        m_group = ssn.substr(3, 2);
        m_serial = ssn.substr(5, 4);
    }
    // postconditions
    BOOST_ASSERT(invariant());
}

std::string SSN::str() const {
    // precondition
    BOOST_ASSERT(invariant());
    std::string result = m_area + '-' + m_group + '-' + m_serial;
    //postcondition
    const std::regex integerRegex("^\\d+$");
    BOOST_ASSERT(invariant());
    BOOST_ASSERT_MSG(
            std::regex_match(result, outputRegex()),
            "String representation matches output regex");
    // The following assertions are actually redundant, as they are implied
    // by the regular expression match. They are only there to demonstrate
    // how regular expressions can make contracts much shorter
    BOOST_ASSERT_MSG(result.size() == 11, "SSN has 11 characters");
    BOOST_ASSERT_MSG(result[3] == '-', "Fourth character is dash");
    BOOST_ASSERT_MSG(result[6] == '-', "Seventh character is dash");
    BOOST_ASSERT_MSG(result.substr(0, 3) != "000", "Area number not zeroes");
    BOOST_ASSERT_MSG(std::regex_match(result.substr(0, 3), integerRegex),
                     "Area number is integer");
    BOOST_ASSERT_MSG(result.substr(0, 3) != "666", "Area number not 666");
    BOOST_ASSERT_MSG(result[0] != 9, "Area number is not ITIN");
    BOOST_ASSERT_MSG(result.substr(4, 2) != "00", "Group number not zeroes");
    BOOST_ASSERT_MSG(std::regex_match(result.substr(4, 2), integerRegex),
                     "Group number is integer");
    BOOST_ASSERT_MSG(result.substr(7, 4) != "0000", "Serial number not zeroes");
    BOOST_ASSERT_MSG(std::regex_match(result.substr(7, 4), integerRegex),
                     "Group number is integer");
    return result;
}

bool SSN::invariant() const {
    BOOST_ASSERT_MSG(m_area != "000", "Area number not zeroes");
    BOOST_ASSERT_MSG(m_area != "666", "Area number not 666");
    BOOST_ASSERT_MSG(m_area[0] != '9', "Area number is not ITIN");
    BOOST_ASSERT_MSG(m_group != "00", "Group number not zeroes");
    BOOST_ASSERT_MSG(m_serial != "0000", "Serial number not zeroes");
    return true;
}

bool SSN::operator==(const SSN& other) const {
    BOOST_ASSERT(invariant());
    bool result = m_area == other.m_area && m_group == other.m_group &&
                  m_serial == other.m_serial;
    BOOST_ASSERT(invariant());
    return result;
}

std::ostream& operator<<(std::ostream& os, const SSN& ssn) {
    os << ssn.str();
    return os;
}
