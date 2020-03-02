#include <hourlyemployee.h>
#include <assertexcept.h>

bool HourlyEmployee::invariant() const {
    BOOST_ASSERT(Employee::invariant());
    BOOST_ASSERT_MSG(false, "Invariant not implemented");
    return true;
}
