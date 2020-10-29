#pragma once

#ifndef TICTACTOE_STREAM_RENDERER_HXX
#define TICTACTOE_STREAM_RENDERER_HXX

#include "renderer.hxx"

#include <iosfwd>

class stream_renderer: public renderer {
  std::ostream& out;

  void render_cell(int index, cell_state cell);

public:
  explicit stream_renderer(std::ostream& out);

  void render_board(const board& board) override;
  void render_message(const std::string& message) override;
};

#endif // TICTACTOE_STREAM_RENDERER_HXX
