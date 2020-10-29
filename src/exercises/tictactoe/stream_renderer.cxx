#include "stream_renderer.hxx"
#include "board.hxx"

#include <ostream>

stream_renderer::stream_renderer(std::ostream& out)
    :out{out}
{
}

void stream_renderer::render_board(const board& board)
{
  for (int line = 0; line < 3; ++line) {
    for (int column = 0; column < 3; ++column) {
      int cell = line * 3 + column;
      out << " ";
      render_cell(cell, board.cells[cell]);
      out << " ";
      if (column < 2)
        out << "|";
    }
    if (line < 2) {
      out << "\n---+---+---";
    }
    out << "\n";
  }
}

void stream_renderer::render_message(const std::string& message)
{
  out << message << std::endl;
}

void stream_renderer::render_cell(int index, cell_state cell)
{
  switch (cell) {
  case cell_state::free:
    out << (index + 1);
    break;
  case cell_state::taken_by_o:
    out << 'O';
    break;
  case cell_state::taken_by_x:
    out << 'X';
    break;
  }
}
