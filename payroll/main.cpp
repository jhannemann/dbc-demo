// dbc-demo - A Design by Contract demonstration project
// Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <assertexcept.h>
#include <employee.h>

int main() {
    try {
        std::vector<Employee*> payroll;

        // build and process payroll

    }
    catch (AssertException& e) {
        std::cerr << "Assertion Exception caught: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (std::runtime_error& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Unknown exception caught\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
