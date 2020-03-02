#ifndef HOURLY_H
#define HOURLY_H

#include "employee.h"
#include "../ssn/ssn.h"

class HourlyEmployee : public Employee {
protected:
    bool invariant() const;
}; // class HourlyEmployee

#endif
