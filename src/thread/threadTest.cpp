#include <string>
#include <thread>
#include <iostream>
#include <algorithm>
#include <functional>
#include <chrono>
#include <future>
#include "gtest/gtest.h"

class threadT : public ::testing::Test {
protected:
    threadT() {
    }
    ~threadT() override {
    }
    void SetUp() override {
    }
    void TearDown() override {
    }
};


int g_num = 0;
void funcPointerEntry()
{
    g_num++;
}

/*
1. 函数指针
*/
TEST_F(threadT, funcPointer)
{
    std::thread t(funcPointerEntry);
    t.join();
    ASSERT_EQ(1, g_num);
}

/*
2. lambda 表达式作为入口
*/
TEST_F(threadT, lambda)
{
    std::thread t([]() {
        g_num++;
    });

    t.join();
    ASSERT_EQ(1, g_num);
}

class MyThread {
public:
    void operator()() {
        g_num++;
    }

    void memberFunc() {
        g_num++;
    }
};

/*
1. 成员函数作为入口
*/
TEST_F(threadT, memberFunc)
{
    MyThread myThread;
    std::thread t(&MyThread::memberFunc, &myThread);
    t.join();
    ASSERT_EQ(1, g_num);
}

/*
1. 函数对象
*/
TEST_F(threadT, detach)
{
    MyThread myThread;
    std::thread t(myThread);
    t.detach();
}

void myprint(const int var, const std::string& mybuf)
{
    std::cout << __FILE__ << "(" << __LINE__ << "): " << __func__ << " var  = " << var << std::endl;
    std::cout << __FILE__ << "(" << __LINE__ << "): " << __func__ << " mybuf  = " << mybuf << std::endl;
}

/*
1. 测试参数值传递
*/
TEST_F(threadT, valueParam)
{
    //1.传递临时对象作为线程参数
    int mvar = 100;
    char mybuf[] = "this is a test";
    std::thread t1(myprint, mvar, std::string(mybuf));
    t1.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

/*
1. 测试callonce 接口
*/
TEST_F(threadT, callOnce)
{
    std::mutex mutexA;
    std::once_flag flag;
    int num = 0;
    std::thread threadA([&]() {
    for (size_t i = 0; i < 10; ++i) {
        std::call_once(flag, funcPointerEntry);
        num++;
    }});

    threadA.join();
    ASSERT_EQ(1, g_num);
    ASSERT_EQ(10, num);
}

/*
packaged_task 
1. 可以作为一个可调用对象作为线程入口。
2. 不可拷贝，只能移动
3. 必须要要先`get_future`再启动线程
4. 在`future` 的`get`函数阻塞
*/

TEST_F(threadT, packagedTask)
{
    std::packaged_task<int()> task([](){
        g_num++;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        return g_num;
    });
    std::future<int> f = task.get_future();
    std::thread t(std::move(task));
    std::cout << " f res = " << f.get() << std::endl; //阻塞在这里
    t.join();
}

/*
1. 与` packaged_task`类似，但是它不是一个可调用对象，函数入口需要通过传参
2.  通过 `set_value` 返回结果，一旦前者设置，立刻返回结果，比前者更灵活
*/
TEST_F(threadT, promise)
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t([&p](){
        p.set_value(100);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "thread end, threadId = " << std::this_thread::get_id() << std::endl;
    });
    std::cout << " f res = " << f.get() << std::endl; //阻塞在这里
    t.join();
}