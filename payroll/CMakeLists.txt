SET(EMPLOYEE_HEADERS employee.h hourlyemployee.h salariedemployee.h)
SET(EMPLOYEE_SOURCES employee.cpp hourlyemployee.cpp salariedemployee.cpp)

link_directories(${CMAKE_BINARY_DIR}/assertexcept
                 ${CMAKE_BINARY_DIR}/ssn
                 ${Boost_LIBRARY_DIRS})

add_library(employee ${EMPLOYEE_HEADERS} ${EMPLOYEE_SOURCES})
add_executable(payroll ${EMPLOYEE_HEADERS} main.cpp)
target_link_libraries(payroll employee assertexcept ssn ${Boost_LIBRARIES})
