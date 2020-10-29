#pragma once

#ifndef TICTACTOE_BOARD_HXX
#define TICTACTOE_BOARD_HXX

#include <array>

enum class cell_state {
  free,
  taken_by_x,
  taken_by_o,
};

struct board {
  std::array<cell_state, 9> cells;
};

#endif // TICTACTOE_BOARD_HXX
