module;

#define BOOST_TEST_MODULE input_test
#include <boost/test/unit_test.hpp>

module input;

import :memory;
import :name;

BOOST_AUTO_TEST_CASE(memory_test)
{
    const auto udev = app::make_udev();
    BOOST_TEST(udev != nullptr);
}

BOOST_AUTO_TEST_CASE(name_test)
{
    BOOST_TEST(app::btn_name("BTN_LEFT") == "LEFT");
    BOOST_TEST(app::key_name("KEY_ENTER") == "ENTER");
}
