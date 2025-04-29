module;

#define BOOST_TEST_MODULE input_test
#include <boost/test/included/unit_test.hpp>

module input;

import :ptr;

BOOST_AUTO_TEST_CASE(ptr_test)
{
    const auto udev = app::make_udev();
    BOOST_TEST(udev != nullptr);
}
