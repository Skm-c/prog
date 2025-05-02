set(SOURCES
	my_test.cpp
)

add_executable(test_long_number ${SOURCES})
target_link_libraries(test_long_number
	gtest_main
	gmock_main
	sort_lib2
)

add_test(test_long_number test_long_number)