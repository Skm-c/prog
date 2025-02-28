#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "merge.hpp"
#include "merge_sort.hpp"

TEST(ArrayEqual, AnyElementsCount) {
	std::vector<int> actual = {4, 2, 5, 1};
	int p = 0;
	int r = 3;
	biv::merge_sort(actual, p, r)
	std::vector<int> expected = {1, 2, 4, 5};
	
	ASSERT_EQ(expected.size(), actual.size())
	
	for (int i = 0; i < actual.size(); i++) {
		ASSERT_EQ(expected[i], actual[i])
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
)
	