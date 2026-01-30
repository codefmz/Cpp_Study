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
        2. 执行两个析构函数
    */
    Config config(1, 2);
    testConfig(std::move(config));
}

auto testLambdaConfig()
{
    Config config(1, 2);
    return [&config]() { /*  引用拷贝 */
        std::cout << "a: " << config.a << ", b: " << config.b << std::endl;
    };
}

/*
   1. 测试lamd 引用捕获与值捕获效果
*/
TEST_F(classT, lambda)
{
    testLambdaConfig()();
}

