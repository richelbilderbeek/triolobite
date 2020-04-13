#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "pieces.h"

/// Game logic
class game
{
public:
  game();

  const grid& get_grid() const noexcept { return m_grid; }
  const pieces& get_player_1() const noexcept { return m_player_1; }
  const pieces& get_player_2() const noexcept { return m_player_2; }
  const pieces& get_undrawn() const noexcept { return m_undrawn; }

private:
  grid m_grid;
  pieces m_player_1;
  pieces m_player_2;
  pieces m_undrawn;
};

int count_pieces(const game& g);

int count_pieces_in_grid(const game& g) noexcept;
int count_pieces_player_1(const game& g) noexcept;
int count_pieces_player_2(const game& g) noexcept;
int count_undrawn_pieces(const game& g) noexcept;

/// Get the initial number of pieces both players draw
constexpr int get_initial_n_pieces() noexcept { return 5; }

void test_game();

#endif // GAME_H
