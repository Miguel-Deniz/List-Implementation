// unittest_SimpleMath.cpp : Defines the entry point for the console application.

#include "gtest/gtest.h"
#include <List.h>

TEST(List, push_back)
{
	List<int> lst1;
	lst1.push_back(1);
	EXPECT_EQ(1, lst1.front());
	EXPECT_EQ(1, lst1.back());

	lst1.push_back(500);
	EXPECT_EQ(1, lst1.front());
	EXPECT_EQ(500, lst1.back());

	lst1.push_back(0);
	EXPECT_EQ(1, lst1.front());
	EXPECT_EQ(0, lst1.back());

	lst1.push_back(-500);
	EXPECT_EQ(1, lst1.front());
	EXPECT_EQ(-500, lst1.back());

	// Test with chars
	List<char> lst2;
	
	lst2.push_back('a');
	EXPECT_EQ('a', lst2.front());
	EXPECT_EQ('a', lst2.back());

	lst2.push_back('x');
	EXPECT_EQ('a', lst2.front());
	EXPECT_EQ('x', lst2.back());

	lst2.push_back('m');
	EXPECT_EQ('a', lst2.front());
	EXPECT_EQ('m', lst2.back());

	lst2.push_back('a');
	EXPECT_EQ('a', lst2.front());
	EXPECT_EQ('a', lst2.back());
}

TEST(List, push_front)
{
	List<int> lst1;

	lst1.push_front(1);
	EXPECT_EQ(1, lst1.front());
	EXPECT_EQ(1, lst1.back());

	lst1.push_front(5);
	EXPECT_EQ(5, lst1.front());
	EXPECT_EQ(1, lst1.back());

	lst1.push_front(50);
	EXPECT_EQ(50, lst1.front());
	EXPECT_EQ(1, lst1.back());

	lst1.push_front(-558);
	EXPECT_EQ(-558, lst1.front());
	EXPECT_EQ(1, lst1.back());
}

TEST(List, mixed_pushes)
{
	List<int> lst;

	lst.push_front(6);
	EXPECT_EQ(6, lst.front());
	EXPECT_EQ(6, lst.back());

	lst.push_back(2);
	EXPECT_EQ(6, lst.front());
	EXPECT_EQ(2, lst.back());

	lst.push_front(85);
	EXPECT_EQ(85, lst.front());
	EXPECT_EQ(2, lst.back());

	lst.push_back(-852);
	EXPECT_EQ(85, lst.front());
	EXPECT_EQ(-852, lst.back());
}

TEST(List, pop_front)
{
	List<int> lst;

	ASSERT_THROW(lst.pop_front(), std::out_of_range);

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	EXPECT_EQ(1, lst.front());

	lst.pop_front();
	EXPECT_EQ(2, lst.front());

	lst.pop_front();
	EXPECT_EQ(3, lst.front());

	lst.pop_front();
	EXPECT_EQ(4, lst.front());

	lst.pop_front();
	EXPECT_EQ(5, lst.front());

	lst.pop_front();
	ASSERT_THROW(lst.pop_front(), std::out_of_range);
}

TEST(List, size)
{
	List<int> lst;

	// Empty list
	EXPECT_EQ(0, lst.size());

	// Add elements
	lst.push_front(1);
	EXPECT_EQ(1, lst.size());

	lst.push_back(54);
	EXPECT_EQ(2, lst.size());

	lst.push_front(5);
	EXPECT_EQ(3, lst.size());

	lst.push_back(85);
	EXPECT_EQ(4, lst.size());

	lst.push_front(0);
	EXPECT_EQ(5, lst.size());

	// Remove elements
	lst.pop_back();
	EXPECT_EQ(4, lst.size());

	lst.pop_front();
	EXPECT_EQ(3, lst.size());

	lst.pop_front();
	EXPECT_EQ(2, lst.size());

	lst.pop_back();
	EXPECT_EQ(1, lst.size());

	lst.pop_back();
	EXPECT_EQ(0, lst.size());

	// Try popping elements out of empty list, and check size
	EXPECT_ANY_THROW(lst.pop_front());
	EXPECT_EQ(0, lst.size());

	EXPECT_ANY_THROW(lst.pop_back());
	EXPECT_EQ(0, lst.size());
}