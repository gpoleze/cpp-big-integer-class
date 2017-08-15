/*
 * LinkedListTest.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: gabrielpferreira
 */


#include "LinkedList.h"
#include "gtest/gtest.h"

namespace {
	class LinkedListTest : public ::testing::Test {
	protected:
		LinkedList<int> list;
	};

	TEST_F(LinkedListTest, to_assure_the_list_is_empty_after_creation){
		ASSERT_TRUE(list.isEmpty());
	}

	TEST_F(LinkedListTest, adding_one_element_should_increase_the_list_size_to_one){
		list.addLast(1);
		ASSERT_EQ(1,list.getSize()) << "size should be equal to 1";
		}

	TEST_F(LinkedListTest,adding_two_element_should_increase_the_list_size_to_two){
		list.addLast(1);
		list.addLast(2);
		EXPECT_EQ(1,list.at(0)) << "list[0] = 1";
		EXPECT_EQ(2,list.at(1)) << "list[2] = 2";
		EXPECT_EQ(2,list.getSize())  << "list.getSize() = 2";
	}
}
