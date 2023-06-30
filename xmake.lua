add_rules("mode.debug", "mode.release")

add_requires("vcpkg::opencascade", "gtest")

target("occtcommon")
    set_kind("shared")
    add_files("src/*.cpp")
    add_includedirs("include")
    add_packages("vcpkg::opencascade")

target("test")
    set_kind("binary")
    add_files("tests/test.cpp")
    add_includedirs("include")
    add_deps("occtcommon")
    add_packages("gtest", "vcpkg::opencascade")
