add_rules("mode.debug", "mode.release")

add_rules("plugin.compile_commands.autoupdate")

set_languages("c++23")
set_warnings("all", "extra", "pedantic")
set_policy("build.c++.modules", true)

set_runtimes("stdc++_shared")

add_requires("pkgconf::gtkmm-4.0", { alias = "gtkmm" })

target("yank-keys", function()
    add_packages("gtkmm")
    add_files(
        "src/window/*.cpp",
        "src/*.cpp"
    )
end)
