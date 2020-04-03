// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "assertexcept.h"
#include <sstream>

void boost::assertion_failed_msg(char const* expr, char const* msg,
                                 char const* function,
                                 char const* file, long line) {
    std::ostringstream message;
    message << "Assertion failed: " << file << ":" << line
            << ": " << function << " " << expr << " " << msg;
    throw AssertException(message.str());
}

void boost::assertion_failed(char const* expr, char const* function,
                             char const* file, long line) {
    std::ostringstream message;
    message << "Assertion failed: " << file << ":" << line
            << ": " << function << " " << expr;
    throw AssertException(message.str());
}
