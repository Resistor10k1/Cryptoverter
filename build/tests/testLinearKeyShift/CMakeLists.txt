cmake_minimum_required(VERSION 3.10)

project(MyDate)

find_package(GTest REQUIRED)

add_executable(MyDate
	main.cpp
	LinearKeyShiftTest.cpp
	LinearKeyShift.h
)
target_link_libraries(MyDate GTest::GTest)

