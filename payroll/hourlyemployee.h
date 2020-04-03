// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef HOURLY_H
#define HOURLY_H

#include "employee.h"
#include "../ssn/ssn.h"

class HourlyEmployee : public Employee {
protected:
    bool invariant() const;
}; // class HourlyEmployee

#endif
