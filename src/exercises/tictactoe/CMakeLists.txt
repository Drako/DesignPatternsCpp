add_library(tictactoe_impl STATIC
        game.hxx game.cxx
        game_state.hxx game_state.cxx
        board.hxx
        player.hxx
        renderer.hxx
        stream_renderer.hxx stream_renderer.cxx
        )
target_include_directories(tictactoe_impl INTERFACE .)

add_executable(tictactoe main.cxx)
target_link_libraries(tictactoe PRIVATE tictactoe_impl)

add_executable(tictactoe_tests game_tests.cxx stream_renderer_tests.cxx)
target_link_libraries(tictactoe_tests PRIVATE tictactoe_impl gtest gtest_main gmock)
add_test(NAME tictactoe_tests COMMAND tictactoe_tests)
