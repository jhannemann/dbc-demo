// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "salariedemployee.h"

#include <assertexcept.h>

#include "../ssn/ssn.h"

bool SalariedEmployee::invariant() const {
    BOOST_ASSERT(Employee::invariant());
    BOOST_ASSERT_MSG(false, "Invariant not implemented");
    return true;
}
