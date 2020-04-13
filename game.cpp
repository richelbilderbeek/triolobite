#include "game.h"

#include <algorithm>
#include <cassert>

game::game(const int rng_seed)
  : m_grid{},
    m_player_1{},
    m_player_2{},
    m_rng_engine{static_cast<unsigned long>(rng_seed)},
    m_undrawn{create_all_pieces()}
{
  assert(count_pieces(*this) == get_total_n_pieces());
  std::shuffle(std::begin(m_undrawn), std::end(m_undrawn), m_rng_engine);
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

piece game::draw()
{
  assert(count_undrawn_pieces(*this) > 0);
  const piece p = m_undrawn.back();
  m_undrawn.pop_back();
  return p;
}

void test_game()
{
  //A game has the correct number of pieces
  {
    const game g;
    assert(count_pieces(g) == get_total_n_pieces());
  }
  //Drawing a pieces reduces the number of undrawn
  {
    game g;
    const int n_before{count_undrawn_pieces(g)};
    g.draw();
    const int n_after{count_undrawn_pieces(g)};
    assert(n_after == n_before - 1);
  }
}
