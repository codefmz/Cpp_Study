#include "gtest/gtest.h"

class classT : public ::testing::Test {
protected:
    classT() {
    }
    ~classT() override {
    }
    void SetUp() override {
    }
    void TearDown() override {
    }
};

struct Config {
    int a;
    int b;

    Config() = default;

    Config(int a, int b) : a(a), b(b) {
        std::cout << "Constructor called" << std::endl;
    }
    Config(const Config &other) {
        a = other.a;
        b = other.b;
        std::cout << "Copy constructor called" << std::endl;
    }

    Config(Config &&other) {
        a = other.a;
        b = other.b;
        std::cout << "Move constructor called" << std::endl;
    }

    Config &operator=(const Config &other) {
        a = other.a;
        b = other.b;
        std::cout << "Copy assignment called" << std::endl;
        return *this;
    }

    Config &operator=(Config &&other) {
        a = other.a;
        b = other.b;
        std::cout << "Move assignment called" << std::endl;
        return *this;
    }

    ~Config() {
        std::cout << "Destructor called" << std::endl;
    }
};

void testConfig(Config config)
{
    std::cout << "a: " << config.a << ", b: " << config.b << std::endl;
}

/*
* 测试函数调用 拷贝流程 
*/
TEST_F(classT, func_class_copy)
{
    /* 
        1. 先执行移动构造函数。
        2.  
    */
    Config config;
    testConfig(std::move(config));
}

auto testLambdaConfig(const Config & config)
{
    return [config]() {
        std::cout << "a: " << config.a << ", b: " << config.b << std::endl;
    };
}

auto test1() {
    return testLambdaConfig(Config(1, 2));
}

TEST_F(classT, lambda)
{
    auto f = test1();
    f();
}

void testQuote(const Config & config)
{
    std::cout << "Quote: a: " << config.a << ", b: " << config.b << std::endl;
}

TEST_F(classT, quote)
{
    Config config(1, 3);
    testQuote(std::move(config));
}

