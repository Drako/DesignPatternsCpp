#include "game_state.hxx"

#include <algorithm>
#include <cassert>

event event::starting_player_determined(player starting_player)
{
  event evt{event_type::starting_player_determined};
  evt.starting_player = starting_player;
  return evt;
}

game_state::game_state(game_state_manager& manager)
    :manager{manager}
{
}

void game_state::on_enter(const event&)
{
}

void game_state::on_leave(const event&)
{
}

determining_starting_player::determining_starting_player(game_state_manager& manager, std::random_device& device)
    :game_state{manager}, rng{device()}, dist{0, 1}
{
}

void determining_starting_player::update()
{
  auto const starting_player = dist(rng) ? player::o : player::x;
  manager.send_event(event::starting_player_determined(starting_player));
}

playing::playing(game_state_manager& manager)
    :game_state{manager}
{
}

void playing::on_enter(const event& evt)
{
  assert(evt.type==event_type::starting_player_determined);
  current_player = evt.starting_player;
  std::fill(game_board.cells.begin(), game_board.cells.end(), cell_state::free);
}

void playing::update()
{
}
