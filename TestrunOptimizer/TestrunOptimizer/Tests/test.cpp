#include "gtest/gtest.h"
#include "DummyClass.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(DummyClassTest, ChangeValue) {
	Dummy obj;
	ASSERT_EQ(obj.get(), 0);
	obj.change(5);
	ASSERT_EQ(obj.get(), 5);
	obj.change(-2);
	ASSERT_NE(obj.get(), 4);
}