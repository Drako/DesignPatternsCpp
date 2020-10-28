add_executable(decorator
        printer.hxx mock_printer.hxx
        decorator.hxx
        stream_printer.cxx stream_printer.hxx stream_printer_tests.cxx
        reversing.cxx reversing.hxx reversing_tests.cxx
        shouting.cxx shouting.hxx shouting_tests.cxx
        prefixing.cxx prefixing.hxx prefixing_tests.cxx
        combined_tests.cxx
        )
target_link_libraries(decorator gtest gtest_main gmock)
add_test(NAME decorator_tests COMMAND decorator)
