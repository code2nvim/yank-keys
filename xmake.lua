add_rules("mode.debug", "mode.release")

add_rules("plugin.compile_commands.autoupdate")

set_languages("c++23")
set_warnings("all", "extra", "pedantic")
set_policy("build.c++.modules", true)

set_runtimes("stdc++_shared")

add_requires("pkgconf::gtkmm-4.0", { alias = "gtkmm" })
add_requires("pkgconf::libudev", { alias = "libudev" })
add_requires("pkgconf::libinput", { alias = "libinput" })

target("yank-keys", function()
    add_packages("gtkmm", "libudev", "libinput")
    add_files(
        "src/input/*.cpp",
        "src/input.cpp",
        "src/window/*.cpp",
        "src/window.cpp",
        "src/main.cpp"
    )
end)

target("test", function()
    add_tests("input_test")
    add_packages("libudev", "libinput")
    add_links("boost_unit_test_framework")
    add_files(
        "src/input/*.cpp",
        "src/input.cpp",
        "test/input_test.cpp"
    )
    add_defines("BOOST_TEST_DYN_LINK")
end)
