#include <fstream>
#include <string>
#include <regex>
#include "gtest/gtest.h"

using namespace std;

class regexT : public ::testing::Test {
protected:
    regexT() {
    }
    ~regexT() override {
    }
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(regexT, test1)
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string test_str = "receipt freind theif receive";
    if (regex_search(test_str, results, r)) {
        cout << results.str() << endl;
    }
}

TEST_F(regexT, test2)
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    string file = "receipt freind theif receive";
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
        cout << it->str() << endl;
    }
}
TEST_F(regexT, test3)
{
    string pattern("[^c]ei");
    regex r(pattern);
    string file = "receipt freind theif receive";
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
        cout << it->str() << endl;
    }


    std::cout << " regix dir = " << REGEX_SRC_DIR << std::endl;
}