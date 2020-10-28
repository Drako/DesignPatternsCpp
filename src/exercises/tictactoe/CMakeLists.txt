add_library(tictactoe_impl STATIC game.hxx game.cxx)
target_include_directories(tictactoe_impl INTERFACE .)

add_executable(tictactoe main.cxx)
target_link_libraries(tictactoe PRIVATE tictactoe_impl)

add_executable(tictactoe_tests game_tests.cxx)
target_link_libraries(tictactoe_tests PRIVATE gtest gtest_main gmock)
add_test(NAME tictactoe_tests COMMAND tictactoe_tests)
