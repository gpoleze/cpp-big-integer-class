#include "BigInteger.h"
#include "gtest/gtest.h"

namespace {
class BigIntegerTest: public ::testing::Test {
protected:
	BigInteger bi;
};

TEST_F(BigIntegerTest, have_a_size_zero_when_empty_constructor_called) {
	ASSERT_EQ(0, bi.getSize());
}
TEST_F(BigIntegerTest, right_assigning_123456789_after_empty_constructor_called) {
	bi = 123456789;
	ASSERT_EQ(123456789, bi);
}
TEST_F(BigIntegerTest, passing_0_as_argumento_to_cosntructor) {
	BigInteger bi(0l);
	ASSERT_EQ(0, bi);
}
TEST_F(BigIntegerTest, passing_biggest_positive_long_number_in_hexadecimal_0x7FFFFFFFFFFFFFFF_as_argument_to_constructor) {
	BigInteger bi(0x7FFFFFFFFFFFFFFF);
	ASSERT_EQ(0x7FFFFFFFFFFFFFFF, bi);
	ASSERT_EQ(19, bi.getSize());
}
TEST_F(BigIntegerTest, passing_smallest_negative_long_number_in_hexadecimal_0x8FFFFFFFFFFFFFFF_as_argument_to_constructor) {
	BigInteger bi(-0x8FFFFFFFFFFFFFFF);
	ASSERT_EQ(-0x8FFFFFFFFFFFFFFF, bi);
	ASSERT_EQ(19, bi.getSize());
}
TEST_F(BigIntegerTest, passing_a_positive_string_as_argument_to_constructor) {
	string s = "123456789132456789132456789";
	BigInteger bi("123456789132456789132456789");
	ASSERT_EQ(s, bi);
	ASSERT_EQ(27, bi.getSize());
}
TEST_F(BigIntegerTest, passing_a_negative_string_as_argument_to_constructor) {
	string s = "-123456789132456789132456789123";
	BigInteger bi("-123456789132456789132456789123");
	ASSERT_EQ(s, bi);
	ASSERT_EQ(30, bi.getSize());
}
TEST_F(BigIntegerTest, passing_another_BigInteger_as_argument_to_constructor) {
	string s = "-123456789132456789132456789";
	BigInteger b1("-123456789132456789132456789");
	BigInteger b2(b1);
	ASSERT_EQ(s, b2);
	ASSERT_EQ(27, b2.getSize());
}
//Equals method
TEST_F(BigIntegerTest,equals_should_be_minus_one_when_b1_is_minus_100_and_b2_is_100) {
	BigInteger b1(-100l);
	BigInteger b2(100l);
	ASSERT_EQ(-1,b1.equals(b2));
}

TEST_F(BigIntegerTest,equals_should_be_minus_one_when_b1_is_10_and_b2_is_100) {
	BigInteger b1(10l);
	BigInteger b2(100l);
	ASSERT_EQ(-1,b1.equals(b2));
}

TEST_F(BigIntegerTest,equals_should_be_minus_one_when_b1_is_123456788_and_b2_is_123456789) {
	BigInteger b1(123456788);
	BigInteger b2(123456789);
	ASSERT_EQ(-1,b1.equals(b2));
}
TEST_F(BigIntegerTest,equals_should_be_minus_one_when_b1_is_minus_123456789_and_b2_is_minus_123456788) {
	BigInteger b1(-123456789l);
	BigInteger b2(-123456788l);
	ASSERT_EQ(-1,b1.equals(b2));
}

TEST_F(BigIntegerTest,equals_should_be_one_when_b1_is_100_and_b2_is_minus_100) {
	BigInteger b1(100l);
	BigInteger b2(-100l);
	ASSERT_EQ(1,b1.equals(b2));
}

TEST_F(BigIntegerTest,equals_should_be_one_when_b1_is_100_and_b2_is_10) {
	BigInteger b1(100l);
	BigInteger b2(10l);
	ASSERT_EQ(1,b1.equals(b2));
}

TEST_F(BigIntegerTest,equals_should_be_one_when_b1_is_123456789_and_b2_is_123456788) {
	BigInteger b1(123456789);
	BigInteger b2(123456788);
	ASSERT_EQ(1,b1.equals(b2));
}
TEST_F(BigIntegerTest,equals_should_be_one_when_b1_is_minus_123456788_and_b2_is_minus_123456789) {
	BigInteger b1(-123456788);
	BigInteger b2(-123456789);
	ASSERT_EQ(1,b1.equals(b2));
}
TEST_F(BigIntegerTest,equals_should_be_zero_when_b1_is_123456789_and_b2_is_123456789) {
	BigInteger b1(123456789);
	BigInteger b2(123456789);
	ASSERT_EQ(0,b1.equals(b2));
}
TEST_F(BigIntegerTest,equals_should_be_zero_when_b1_is_minus_123456789_and_b2_is_minus_123456789) {
	BigInteger b1(-123456789);
	BigInteger b2(-123456789);
	ASSERT_EQ(0,b1.equals(b2));
}

//Comparison - Greater Than
TEST_F(BigIntegerTest,comparison_greater_than_true_when_b1_is_minus_123456788_and_b2_is_minus_123456789) {
BigInteger b1(-123456788);
BigInteger b2(-123456789);
ASSERT_TRUE(b1 > b2);
}
TEST_F(BigIntegerTest,comparison_greater_than_true_when_b1_is_123456789_and_b2_is_123456789) {
BigInteger b1(123456789);
BigInteger b2(123456788);
ASSERT_TRUE(b1 > b2);
}
TEST_F(BigIntegerTest,comparison_greater_than_false_when_b1_is_10_and_b2_is_19) {
BigInteger b1(10);
BigInteger b2(19);
ASSERT_FALSE
(b1 > b2);
}
//Comparison - Equal to Greater Than
TEST_F(BigIntegerTest,comparison_equal_to_or_greater_than_true_when_b1_is_minus_123456789_and_b2_is_minus_123456789) {
BigInteger b1(-123456789);
BigInteger b2(-123456789);
ASSERT_TRUE(b1 >= b2);
}

TEST_F(BigIntegerTest,comparison_equal_to_or_greater_than_true_when_b1_is_minus_123456788_and_b2_is_minus_123456789) {
BigInteger b1(-123456788);
BigInteger b2(-123456789);
ASSERT_TRUE(b1 >= b2);
}
TEST_F(BigIntegerTest,comparison_equal_to_or_greater_than_true_when_b1_is_123456789_and_b2_is_123456789) {
BigInteger b1(123456789);
BigInteger b2(123456788);
ASSERT_TRUE(b1 >= b2);
}
TEST_F(BigIntegerTest,comparison_equal_to_or_greater_than_false_when_b1_is_10_and_b2_is_19) {
BigInteger b1(10);
BigInteger b2(19);
ASSERT_FALSE
(b1 >= b2);
}
//Comparison - Less Than
TEST_F(BigIntegerTest,comparison_less_than_true_when_b1_is_minus_123456789_and_b2_is_minus_123456788) {
BigInteger b1(-123456789);
BigInteger b2(-123456788);
ASSERT_TRUE(b1 < b2);
}
TEST_F(BigIntegerTest,comparison_less_than_true_when_b1_is_123456788_and_b2_is_123456789) {
BigInteger b1(123456788);
BigInteger b2(123456789);
ASSERT_TRUE(b1 < b2);
}
TEST_F(BigIntegerTest,comparison_less_than_false_when_b1_is_19_and_b2_is_10) {
BigInteger b1(19);
BigInteger b2(10);
ASSERT_FALSE
(b1 < b2);
}
//Comparison - Equal to Less Than
//Comparison - Equal to
//Comparison - Not Equal to

}
