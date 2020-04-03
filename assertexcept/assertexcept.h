// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ASSERTEXCEPT_H
#define ASSERTEXCEPT_H

#include <string>

#ifdef NDEBUG
#define BOOST_DISABLE_ASSERTS
#else
#define BOOST_ENABLE_ASSERT_HANDLER
#define BOOST_ENABLE_ASSERT_DEBUG_HANDLER
#endif

#include <boost/assert.hpp>

class AssertException {
public:
    AssertException(const std::string& msg) : m_msg(msg) {};

    const std::string& what() const { return m_msg; }

private:
    const std::string m_msg;
};

namespace boost {
    void assertion_failed_msg(char const* expr, char const* msg,
                              char const* function,
                              char const* file, long line);

    void assertion_failed(char const* expr,
                          char const* function,
                          char const* file, long line);
}

#endif
