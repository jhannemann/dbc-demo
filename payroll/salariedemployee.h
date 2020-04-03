// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SALARIED_H
#define SALARIED_H

#include "employee.h"

class SalariedEmployee : public Employee {
protected:
    bool invariant() const;
};

#endif
