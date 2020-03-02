#include "assertexcept.h"
#include <sstream>

void boost::assertion_failed_msg(char const* expr, char const* msg,
                                 char const* function,
                                 char const* file, long line) {
    std::ostringstream message;
    message << "Assertion failed: " << file << ":" << line
            << ": " << function << " " << expr << " " << msg;
    throw AssertException(message.str());
}

void boost::assertion_failed(char const* expr, char const* function,
                             char const* file, long line) {
    std::ostringstream message;
    message << "Assertion failed: " << file << ":" << line
            << ": " << function << " " << expr;
    throw AssertException(message.str());
}
