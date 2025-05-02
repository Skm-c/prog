#include <gtest/gtest.h>

#include "long_number.hpp"

using biv::LongNumber;

class LongNumbers : public testing::Test {
	public:
		LongNumber zero{"0"};
		LongNumber one{"1"};
		LongNumber m_one{"-1"};
		LongNumber two{"2"};
		LongNumber three{"3"};
		LongNumber five{"5"};
		LongNumber seven{"7"};
		LongNumber ten{"10"};
		
};

TEST_F(LongNumbers, equal) {
	EXPECT_TRUE(one == one);
	EXPECT_FALSE(zero == one);
	EXPECT_FALSE(one == m_one);
}

TEST_F(LongNumbers, not_equal) {
	EXPECT_TRUE(zero != one);
	EXPECT_FALSE(one != one);
	EXPECT_TRUE(one != m_one);
}

TEST_F(LongNumbers, more) {
	EXPECT_TRUE(one > zero);
	EXPECT_FALSE(zero > one);
	EXPECT_FALSE(m_one > one);
}

TEST_F(LongNumbers, less) {
	EXPECT_TRUE(zero < one);
	EXPECT_FALSE(one < zero);
	EXPECT_FALSE(one < m_one);
}

TEST_F(LongNumbers, summ) {
	EXPECT_EQ(two, one + one);
	EXPECT_EQ(zero, one + m_one);
	EXPECT_EQ(seven, two + five);	
}

TEST_F(LongNumbers, substraction) {
	EXPECT_EQ(zero, one - one);
	EXPECT_EQ(one, two - one);
	EXPECT_EQ(two, one - m_one);
}


TEST_F(LongNumbers, multiply) {
	EXPECT_EQ(one, one * one);
	EXPECT_EQ(ten, two * five);
	EXPECT_EQ(m_one, one * m_one);
}

TEST_F(LongNumbers, division) {
	EXPECT_EQ(one, one / one);
	EXPECT_EQ(two, ten / five);
	EXPECT_EQ(m_one, one / m_one);
}


TEST_F(LongNumbers, remainder) {
	EXPECT_EQ(one, three % two);
	EXPECT_EQ(zero, ten % five);
	EXPECT_EQ(zero, one % one);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
