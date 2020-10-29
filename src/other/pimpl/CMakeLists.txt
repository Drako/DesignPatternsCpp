add_executable(pimpl
        foo.hxx foo.cxx foo_tests.cxx
        )
target_link_libraries(pimpl gtest gtest_main)
add_test(NAME pimpl_tests COMMAND pimpl)
