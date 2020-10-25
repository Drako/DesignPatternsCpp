add_executable(singleton
        non_constructible.cxx non_constructible.hxx non_constructible_tests.cxx
        constructible.cxx constructible.hxx constructible_tests.cxx
        static.cxx static.hxx static_tests.cxx
        )
target_link_libraries(singleton gtest gtest_main)
add_test(singleton_tests COMMAND singleton)
