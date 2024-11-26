set(CMAKE_AUTOMOC ON)

link_directories(${PROJECT_BINARY_DIR}/assertexcept)

configure_file(ssntest.py ssntest.py COPYONLY)

add_executable(ssntest ssntest.cpp)
add_test(SSNTest ssntest)
target_link_libraries(ssntest Qt6::Test employee ssn assertexcept)
