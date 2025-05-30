module;

#define BOOST_TEST_MODULE input_test
#include <boost/test/unit_test.hpp>

module input;

import :memory;
import :name;
import :token;

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

BOOST_AUTO_TEST_CASE(token_test)
{
    BOOST_TEST(app::to_string(app::Token { 'a' }) == "a");
    BOOST_TEST(app::to_string(app::Token { ' ' }) == "space");
    BOOST_TEST(app::to_string(app::Token { "enter" }) == "enter");
}
