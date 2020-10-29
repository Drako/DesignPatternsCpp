#include <gtest/gtest.h>

#include "stream_renderer.hxx"

#include <sstream>

TEST(StreamRendererTest, ShouldRenderNumbersForEmptyField)
{
  board b{};
  std::ostringstream strm;
  stream_renderer renderer{strm};

  renderer.render_board(b);

  EXPECT_EQ(strm.str(),
      " 1 | 2 | 3 \n"
      "---+---+---\n"
      " 4 | 5 | 6 \n"
      "---+---+---\n"
      " 7 | 8 | 9 \n"
  );
}

TEST(StreamRendererTest, ShouldRenderTakenFieldsCorrectly)
{
  board b{};
  b.cells[2] = cell_state::taken_by_x;
  b.cells[4] = cell_state::taken_by_o;

  std::ostringstream strm;
  stream_renderer renderer{strm};

  renderer.render_board(b);

  EXPECT_EQ(strm.str(),
      " 1 | 2 | X \n"
      "---+---+---\n"
      " 4 | O | 6 \n"
      "---+---+---\n"
      " 7 | 8 | 9 \n"
  );
}

TEST(StreamRendererTest, ShouldRenderMessages)
{
  std::ostringstream strm;
  stream_renderer renderer{strm};

  renderer.render_message("hello");

  EXPECT_EQ(strm.str(), "hello\n");
}
