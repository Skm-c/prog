#include <gtest/gtest.h>

#include "vector.hpp"

using biv::Vector;


TEST(VectorTest, DefaultConstructor) {
    Vector<int> v;
    EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorTest, PushBack) {
    Vector<int> v;
   
    v.push_back(9);
    EXPECT_EQ(v.get_size(), 1);
}

TEST(VectorTest, Remove) {
    Vector<int> v;
	
    v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(v.get_size(), 3);
	
	v.remove_first(2);
    EXPECT_EQ(v.get_size(), 2);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
