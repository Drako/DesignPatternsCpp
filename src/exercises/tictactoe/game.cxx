#include "game.hxx"

#include <cassert>

game::game(renderer& output)
    :output{output}, determining_starting_player_state{*this, rd}, playing_state{*this},
     current_state{&determining_starting_player_state}
{
}

void game::send_event(const event& evt)
{
  current_state->on_leave(evt);
  switch (evt.type) {
  case event_type::starting_player_determined:
    assert(current_state==&determining_starting_player_state);
    current_state = &playing_state;
    break;
  case event_type::win:
    [[fallthrough]];
  case event_type::quit:
    current_state = nullptr;
    return;
  }
  current_state->on_enter(evt);
}

void game::run()
{
  while (current_state) {
    current_state->update();
  }
}

determining_starting_player const* game::get_determining_starting_player_state() const
{
  return &determining_starting_player_state;
}

playing const* game::get_playing_state() const
{
  return &playing_state;
}

game_state const* game::get_current_state() const
{
  return current_state;
}
