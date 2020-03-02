#include "salariedemployee.h"

#include <assertexcept.h>

#include "../ssn/ssn.h"

bool SalariedEmployee::invariant() const {
    BOOST_ASSERT(Employee::invariant());
    BOOST_ASSERT_MSG(false, "Invariant not implemented");
    return true;
}
