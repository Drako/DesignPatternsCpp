add_executable(iterators
        int_range.cxx int_range.hxx int_range_tests.cxx
        )
target_link_libraries(iterators gtest gtest_main)
add_test(NAME iterators_tests COMMAND iterators)
