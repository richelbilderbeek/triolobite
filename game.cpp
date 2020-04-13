#include "game.h"
#include <cassert>

game::game()
  : m_grid{},
    m_player_1{},
    m_player_2{},
    m_undrawn{create_all_pieces()}
{
  assert(count_pieces(*this) == get_total_n_pieces());
}

int count_pieces(const game& g)
{
  return
    count_pieces_player_1(g) +
    count_pieces_player_2(g) +
    count_undrawn_pieces(g) +
    count_pieces_in_grid(g)
  ;
}

int count_pieces_player_1(const game& g) noexcept
{
  return static_cast<int>(g.get_player_1().size());
}

int count_pieces_player_2(const game& g) noexcept
{
  return static_cast<int>(g.get_player_2().size());
}

int count_undrawn_pieces(const game& g) noexcept
{
  return static_cast<int>(g.get_undrawn().size());
}

int count_pieces_in_grid(const game& g) noexcept
{
  return count_pieces(g.get_grid());
}

void test_game()
{
  //A game has the correct number of pieces
  {
    const game g;
    assert(count_pieces(g) == get_total_n_pieces());
  }
}
