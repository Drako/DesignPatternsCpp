add_executable(builder
        server_config.cxx server_config.hxx server_config_tests.cxx
        )
target_link_libraries(builder gtest gtest_main)
add_test(builder_tests COMMAND builder)
