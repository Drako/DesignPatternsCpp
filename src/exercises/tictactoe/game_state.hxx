#pragma once

#ifndef TICTACTOE_GAME_STATE_HXX
#define TICTACTOE_GAME_STATE_HXX

#include "player.hxx"
#include "board.hxx"

#include <random>

enum class event_type {
  starting_player_determined,
  win,
  tie,
  play_again,
  quit,
};

struct event {
  event_type type;
  union {
    player starting_player;
    player winning_player;
  };

  static event starting_player_determined(player starting_player);
};

struct game_state_manager {
  virtual ~game_state_manager() = default;

  virtual void send_event(event const&) = 0;
};

class game_state {
protected:
  game_state_manager& manager;

public:
  explicit game_state(game_state_manager& manager);

  virtual ~game_state() = default;

  virtual void on_enter(event const&);
  virtual void on_leave(event const&);
  virtual void update() = 0;
};

class determining_starting_player: public game_state {
  std::mt19937 rng;
  std::uniform_int_distribution<int> dist;

public:
  determining_starting_player(game_state_manager& manager, std::random_device& device);

  void update() override;
};

class playing: public game_state {
  player current_player{};
  board game_board{};

public:
  explicit playing(game_state_manager& manager);

  void on_enter(event const& evt) override;
  void update() override;
};

#endif // TICTACTOE_GAME_STATE_HXX
