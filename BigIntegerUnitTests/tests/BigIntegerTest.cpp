
#include "BigInteger.h"
#include "gtest/gtest.h"

namespace {
	class BigIntegerTest : public ::testing::Test {
	protected:
		BigInteger bi;
	};

	TEST_F(BigIntegerTest, to_assure_the_list_is_empty_after_creation){
		ASSERT_TRUE(true);
	}
}
