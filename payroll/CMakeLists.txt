SET(EMPLOYEE_HEADERS employee.h hourlyemployee.h salariedemployee.h)
SET(EMPLOYEE_SOURCES employee.cpp hourlyemployee.cpp salariedemployee.cpp)

configure_file(names.csv names.csv COPYONLY)
configure_file(generate_data.py generate_data.py COPYONLY)

link_directories(${CMAKE_BINARY_DIR}/assertexcept
                 ${CMAKE_BINARY_DIR}/ssn
                 ${Boost_LIBRARY_DIRS})

add_library(employee ${EMPLOYEE_HEADERS} ${EMPLOYEE_SOURCES})
add_executable(payroll ${EMPLOYEE_HEADERS} main.cpp)
target_link_libraries(payroll employee ssn assertexcept ${Boost_LIBRARIES})
