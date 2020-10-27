set(bf_SOURCES
        vm.cxx vm.hxx
        instruction.cxx instruction.hxx
        )

add_executable(bf main.cxx interpreter.hxx ${bf_SOURCES})

add_executable(bf_test vm_tests.cxx instruction_tests.cxx ${bf_SOURCES})
target_link_libraries(bf_test gtest gtest_main)
add_test(NAME bf_tests COMMAND bf_test)
