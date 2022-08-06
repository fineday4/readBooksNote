#include <vector>
#include "gtest/gtest.h"

using namespace std;

//case 1. 使用TEST实现单个用例的测试
int myAdd(const int &b)
{
	return 4 + b;
}

TEST(myAdd, 4plus4)
{
	EXPECT_EQ(myAdd(4), 8);
	EXPECT_TRUE(true);
}

//case 2. 使用 AddTestCls + TEST_P + INSTANTIATE_TEST_CASE_P实现多个测试用例的测试
class AddTestCls: public::testing::TestWithParam<int>
{
};

TEST_P(AddTestCls, ExpectTrue)
{
	int n = GetParam();
	EXPECT_TRUE(myAdd(n));
}

TEST(ArrayContent, Compare) {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {1,3,4,5,6};
    for(int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]) << "a compare with b NG: xx" << i;
    }
}

INSTANTIATE_TEST_CASE_P(TrueReturn, AddTestCls, testing::Values(3,4,5,6,7));

 
