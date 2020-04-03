// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <hourlyemployee.h>
#include <assertexcept.h>

bool HourlyEmployee::invariant() const {
    BOOST_ASSERT(Employee::invariant());
    BOOST_ASSERT_MSG(false, "Invariant not implemented");
    return true;
}
