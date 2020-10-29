#include <gtest/gtest.h>

#include "game.hxx"
#include "stream_renderer.hxx"

TEST(GameTest, GameStartsWithDeterminingStartingPlayer)
{
  stream_renderer r{std::cout};
  game g{r};
  EXPECT_EQ(g.get_current_state(), g.get_determining_starting_player_state());
}

TEST(GameTest, DeterminingStartingPlayerSwitchesToPlaying)
{
  stream_renderer r{std::cout};
  game g{r};
  g.send_event(event::starting_player_determined(player::x));
  EXPECT_EQ(g.get_current_state(), g.get_playing_state());
}
