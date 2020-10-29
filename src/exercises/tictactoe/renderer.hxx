#pragma once

#ifndef TICTACTOE_RENDERER_HXX
#define TICTACTOE_RENDERER_HXX

#include "board.hxx"

#include <string>

struct renderer {
  virtual ~renderer() = default;

  virtual void render_board(board const&) = 0;
  virtual void render_message(std::string const&) = 0;
};

#endif // TICTACTOE_RENDERER_HXX
