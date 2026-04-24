#include "gtest/gtest.h"
#include <string_view>
#include <iostream>
#include <format>

class stringview : public ::testing::Test {
protected:
    stringview() {
    }
    ~stringview() override {
    }
    void SetUp() override {
    }
    void TearDown() override {
    }
};


std::string_view extractExtension(std::string_view filename)
{
    return filename.substr(filename.rfind('.'));
}

TEST_F(stringview, testType) {
    std::string fileName = "example.txt";
    ASSERT_EQ(extractExtension(fileName), ".txt");
    std::cout << std::format("C++ string Extracted extension: {}", extractExtension(fileName)) << std::endl;

    const char *filePath = "/path/to/example.txt.exe";
    ASSERT_EQ(extractExtension(filePath), ".exe");
    std::cout << std::format("C char * Extracted extension: {}", extractExtension(filePath)) << std::endl;

    ASSERT_EQ(extractExtension("ttt.pdf"), ".pdf");
    std::cout << std::format("literal Extracted extension: {}", extractExtension("ttt.pdf")) << std::endl;
}