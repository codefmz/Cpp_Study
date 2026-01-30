#include <string>
#include <algorithm>
#include <functional>
#include "gtest/gtest.h"
#include "interface.h"

using namespace std;

class templateT : public ::testing::Test {
protected:
    templateT() {
    }
    ~templateT() override {
    }
    void SetUp() override {
    }
    void TearDown() override {
    }
};

/* 类型模板参数 */
template <typename T>
int compare(const T& a, const T& b)
{
    std::cout << "typeid: " << typeid(T).name() << std::endl;
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    }

    return 0;
}

class TestA {
public:
    TestA(int num) : num(num) {
    }
    int operator<(const TestA& a) const {
        return num < a.num;
    }
    int operator>(const TestA& a) const {
        return num > a.num;
    }

private:
    int num;
};

/*
 1. 测试基础类型使用模版
 2. 类操作符重载使模版
*/
TEST_F(templateT, func_template) {
    EXPECT_EQ(compare(1, 2), -1);
    TestA a1(1), a2(2);
    EXPECT_EQ(compare(a1, a2), -1);
}

/* 非类型模板参数 */
template<typename T, int N, int M>
int compare(T (&p1)[N], T (&p2)[M])
{
    std::cout << "N: " << N << " M: " << M << std::endl;
    std::cout << "typeid: " << typeid(T).name() << std::endl;
    return 0;
}

/*
 1. 测试模版长度推导
*/
TEST_F(templateT, auto_calib_num) {
    const char p1[] = "helloeeeeee";
    const char p2[] = "world";
    EXPECT_EQ(compare(p1, p2), 0);

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(compare(arr1, arr2), 0);
}

int process(int& x) {
    return 1;
}
int process(int&& x) {
    return 2;
}

template <typename T>
int wrapper(T&& arg) {
    return process(arg);
}


template <typename T>
int wrapper_forward(T&& arg) {
    return process(std::forward<T>(arg));
}

/*
 1. 测试 forward 用法
*/
TEST_F(templateT, forward) {
    int x = 1;
    EXPECT_EQ(wrapper(x), 1);
    EXPECT_NE(wrapper(std::move(x)), 2);

    EXPECT_EQ(wrapper_forward(x), 1);
    EXPECT_EQ(wrapper_forward(std::move(x)), 2);
}

/*
 1. 测试pimpl, cheshireCat模版
*/
TEST_F(templateT, cheshireCat) {
    Widget w;
    w.doSomething();
}

