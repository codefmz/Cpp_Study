#include <fstream>
#include <string>
#include <functional>
#include "gtest/gtest.h"

class pointerT : public ::testing::Test {
protected:
    pointerT() {
    }

    ~pointerT() override {
    }

    void SetUp() override {
    }

    void TearDown() override {
    }
};

class TestPointerClass {
public:
    TestPointerClass() {
        std::cout << "TestPointerClass()" << std::endl;
    }

    ~TestPointerClass() {
        std::cout << "~TestPointerClass()" << std::endl;
    }
};

/*
 测试共享指针计数
*/
TEST_F(pointerT, shared_ptr_cnt) {
    std::shared_ptr<int> p1 = std::make_shared<int>(1);
    std::shared_ptr<std::string> p2 = std::make_shared<std::string>(3, 'c');
    std::shared_ptr<TestPointerClass> p3 = std::make_shared<TestPointerClass>();

    EXPECT_EQ(*p2, "ccc");
    auto p4 = p1;
    EXPECT_TRUE(p2.unique());
    EXPECT_EQ(p1.use_count(), 2);
    EXPECT_EQ(p4.use_count(), 2);
}


class TestB;

class TestA {
public:
    TestA() {
        std::cout << "TestA()" << std::endl;
    };

    ~TestA() {
        std::cout << "~TestA()" << std::endl;
    }

public:
    std::shared_ptr<TestB> pb;
};

class TestB {
public:
    TestB() {
        std::cout << "TestB()" << std::endl;
    };

    ~TestB() {
        std::cout << "~TestB()" << std::endl;
    }

public:
    std::shared_ptr<TestA> pa;
};

/*
 测试循环引用
*/
TEST_F(pointerT, circle_refer) {
    std::shared_ptr<TestA> pa = std::make_shared<TestA>();
    std::shared_ptr<TestB> pb = std::make_shared<TestB>();
    pa->pb = pb;
    pb->pa = pa;

    EXPECT_EQ(pa.use_count(), 2);
    EXPECT_EQ(pb.use_count(), 2);
}

class TestLambdaShared : public std::enable_shared_from_this<TestLambdaShared> {
public:
    TestLambdaShared() {
        std::cout << "TestLambdaShared()" << std::endl;
    }

    void init() {
        int b = 0;
        auto self = weak_from_this();
        callback = [self, &b]() {
            if (auto sp = self.lock()) {
                std::cout << "TestLambdaShared::callback()" << std::endl;
                std::cout << " a = " << sp->a << std::endl;
                std::cout << " b = " << b << std::endl;
            }
        };
    }

    ~TestLambdaShared() {
        std::cout << "~TestLambdaShared()" << std::endl;
    }

    void run() {
        callback();
    }

private:
    int a = 0;
    std::function<void()> callback;
};

/*
 测试 lambda 共享指针对象，必须使用 weak_ptr， 否则会有循环引用的问题
*/
TEST_F(pointerT, lambda_shared) {
    auto t = std::make_shared<TestLambdaShared>();
    t->init();
    t->run();
}
