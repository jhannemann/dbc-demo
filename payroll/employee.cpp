// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <employee.h>
#include <assertexcept.h>

bool Employee::invariant() const {
    BOOST_ASSERT_MSG(false, "Invariant not implemented");
    return true;
}
