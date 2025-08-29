module;

#define BOOST_TEST_MODULE data_test

#include <boost/test/unit_test.hpp>

module data;

import :modifier;

BOOST_AUTO_TEST_CASE(token_test)
{
    int num = 1;
    BOOST_TEST(num == 1);
}
