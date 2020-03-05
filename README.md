Design by Contract Demo
=======================

This code is used in both my undergraduate and graduate classes
on software engineering
at [Kentucky State University](https://www.kysu.edu).

It demonstrates the design and implementation of a software system
around the following concepts:
-   [Hoare Logic](https://en.wikipedia.org/wiki/Hoare_logic),
-   [Assertions](https://en.wikipedia.org/wiki/Assertion_(software_development))
    (Using the
    [Boost.Assert](https://www.boost.org/doc/libs/1_72_0/libs/assert/doc/html/assert.html)
    Library)
-   [Design by Contract](https://en.wikipedia.org/wiki/Design_by_contract)
-   [Unit Testing](https://en.wikipedia.org/wiki/Unit_testing)
    (using the [Qt Test Framework](https://doc.qt.io/qt-5/qttest-index.html))
-   The [CMake](https://cmake.org) build and configuration system
-   The CTest testing client part of CMake

The Employee Class Hierarchy
----------------------------

The basic setup is a starting point for an assignment
in which students will design a class hierarchy based on the classic
notion of a general `Employee` abstract base class,
for which `pay()` is determined differently,
depending on whether an employee is salaried or being paid on an hourly basis.
A driver program then simulates a payroll processing run
by filling a polymorphic `std::vector<Employee*>`
and iterating over it to print out paychecks.

The Social Security Number Class
--------------------------------

To help students get started,
the demo code provides a class `SSN`,
which constructs
[valid social security numbers](https://en.wikipedia.org/wiki/Social_Security_number#Valid_SSNs).
The class has an appropriate invariant,
and all member functions have pre- and postconditions as neeeded.
The constructor in particular accepts a `std::string` in a variety of formats.
As required by DbC, the format can be matched
via a publicly available input regular expression,
and the resulting SSN string representation,
obtained via the `SSN::str()` member function,
will match a corresponding output regular expression.

### A Note on C++11 Regular Expressions as Static Data Members

Regular expressions have been added to the language with the C++11 standard,
so the demo code requires a compiler compliant with at least that standard.

The input and output regular expressions are wrapped in static member functions.
This avoids an
*initialization of static data member may throw an exception that cannot be caught*
warning, which can occur
if the regular expression would simply be stored as a static data member.
This is a case of the
[static initialization order problem for static data members](https://isocpp.org/wiki/faq/ctors#static-init-order-on-first-use-members).

To demonstrate how much more compact assertions can be
when using regular expressions for pattern matching,
the `SSN:str()` member function contains 11 (!) additional postconditions,
which together achieve the same result as the single match to the output regex.

The input regular expression is
```
^(?!000)(?!666)(?!9)\d{3}([- ]?)(?!00)\d{2}\1(?!0000)\d{4}$
```
and the output regular expression is
```
^(?!000)(?!666)(?!9)\d{3}-(?!00)\d{2}-(?!0000)\d{4}$
```
I.e. the input regular expression matches all valid combinations of digits,
with a dash or space as separator or no separator at all,
whereas the output regular expression requires the sparators to be dashes only.
There is no deeper reason behind this particular set of requirements
other than it provides for a richer set of pre- and postconditions
for demonstration purposes.

The input and output regular expressions can be checked
and are nicely explained at <https://www.regexpal.com>.

Assertions and Unit Testing
---------------------------

The C++ standard `assert()` macro,
provided in the `<cassert>` header,
calls `std::abort()` to terminate the program,
unless the `NDEBUG` macro is defined.
Specifically,
`assert()` does not accommodate throwing an exception,
which is appropriate in a DbC context,
as one cannot recover from a failed assertion.

In a unit testing context, however,
it is important to check the expected behavior of failed preconditions,
especially in the context of constructors.
The demo code therefore relies on the
[Boost.Assert](https://www.boost.org/doc/libs/1_72_0/libs/assert/doc/html/assert.html)
library,
which provides a way to register handler functions to assertions,
which in turn can throw exceptions
(in this case a `AssertExeption`).
This capability is provided in the `assertexcept` subdirectory of the project.
The unit tests can then use Qt's `QVERIFY_EXCEPTION_THROWN` macro
to generate expected failures
without aborting the ongoing execution of the unit test.
Since release builds define the `NDEBUG` macro,
these tests can be skipped via the `QSKIP` macro
to avoid generating unexpected failures when testing a release build.

Building the Software and Running the Tests
-------------------------------------------

The software can be configured and built using CMake's GUI
or the console-based `ccmake` program.
The `CMakeLists.txt` file provides for an option to enable or disable testing.
If testing is disabled,
Qt is not needed as a dependency at all.
If testing is enabled,
tests can be run by the `make test` command
(if makefiles have been chosen as CMake's backend generator)
or by running CMake's `ctest` program.

Student Assignments
-------------------

Students at the undergraduate level will be expected to design and implement
(possibly abstract)
classes `Employee`, `SalariedEmployee`, and `HourlyEmployee`.
Special attention should be paid to correctly formulate preconditions,
invariants, and postconditions
in the light of the given inheritance hierarchy.

In addition, students at the graduate level are then expected
to also create data-driven unit tests
and demonstrate that all tests are passed for all classes and their assertions,
possibly by creating a pipeline for a contiuous integration tool like
[Jenkins](https://jenkins.io).
