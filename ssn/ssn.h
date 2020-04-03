// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SSN_H
#define SSN_H

#include <string>
#include <iostream>
#include <regex>

class SSN {
public:
    explicit SSN(const std::string& ssn);

    std::string str() const;

    bool operator==(const SSN& other) const;

    static const std::regex inputRegex();

    static const std::regex outputRegex();

protected:
    bool invariant() const;

private:
    std::string m_area;
    std::string m_group;
    std::string m_serial;
};

std::ostream& operator<<(std::ostream& os, const SSN& ssn);

#endif // SSN_H
