add_executable(dependency_injection
        writer.cxx writer.hxx
        mock_writer.hxx
        greeter.cxx greeter.hxx
        injector_tests.cxx
        )
target_link_libraries(dependency_injection gtest gtest_main gmock fruit)
target_include_directories(dependency_injection PRIVATE
        ${CMAKE_SOURCE_DIR}/contrib/fruit/include
        ${CMAKE_BINARY_DIR}/contrib/fruit/include
        )
add_test(NAME dependency_injection_tests COMMAND dependency_injection)
