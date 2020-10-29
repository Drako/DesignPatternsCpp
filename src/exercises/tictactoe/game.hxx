#pragma once

#ifndef TICTACTOE_GAME_HXX
#define TICTACTOE_GAME_HXX

#include <random>

#include "game_state.hxx"
#include "renderer.hxx"

class game: public game_state_manager {
  renderer& output;

  std::random_device rd;

  determining_starting_player determining_starting_player_state;
  playing playing_state;

  game_state* current_state;

public:
  explicit game(renderer& output);

  determining_starting_player const* get_determining_starting_player_state() const;
  playing const* get_playing_state() const;
  game_state const* get_current_state() const;

  void send_event(const event& evt) override;

  void run();
};

#endif // TICTACTOE_GAME_HXX
