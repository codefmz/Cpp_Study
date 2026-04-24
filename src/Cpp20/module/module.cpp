#include "gtest/gtest.h"

class module : public ::testing::Test {
protected:
    module() {
    }
    ~module() override {
    }
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(module, test_1) {
    ASSERT_EQ(1, 1);
}