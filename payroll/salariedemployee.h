#ifndef SALARIED_H
#define SALARIED_H

#include "employee.h"

class SalariedEmployee : public Employee {
protected:
    bool invariant() const;
};

#endif
