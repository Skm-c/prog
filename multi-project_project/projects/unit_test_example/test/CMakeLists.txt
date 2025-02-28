set(SOURCES
	merge_test.cpp
)

add_executable(merge_test ${SOURCES})
target_link_libraries(merge_test
	gtest_main
	gmock_main
	sort_lib
)

add_test(merge_test merge_test)