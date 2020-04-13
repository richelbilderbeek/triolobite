#include "grid.h"
#include <cassert>

grid::grid()
{

}

void grid::add_piece(
  const piece& p,
  const placement& pl
)
{
  assert(can_add_piece(p, pl));
  m_pieces.push_back(std::make_pair(p, pl));
}

bool grid::can_add_piece(
  const piece& ,
  const placement& pl
) const
{
  if (is_taken(pl, *this)) return false;
  return true;
}

int count_pieces(const grid& g) noexcept
{
  return static_cast<int>(g.get_pieces().size());
}

grid create_test_grid() noexcept
{
  grid g;
  g.add_piece();
  return g;
}

bool is_taken(const placement& pl, const grid& g)
{
  return is_taken(get_x(pl), get_y(pl), g);
}

bool is_taken(const int x, const int y, const grid& g)
{
  for (const auto& piece_with_placement: g.get_pieces())
  {
    const placement& p = piece_with_placement.second;
    if (get_x(p) == x && get_y(p) == y) return true;
  }
  return false;
}

void test_grid()
{
  //A grid is empty by default
  {
    const grid g;
    assert(count_pieces(g) == 0);
  }
  //Add a piece is noted
  {
    grid g;
    g.add_piece(); //Default piece, default placement
    assert(count_pieces(g) == 1);
  }
  //Detect center position is taken
  {
    const grid g = create_test_grid();
    assert(is_taken(placement(), g));
  }
  //Add a piece is noted
  {
    grid g;
    const piece p;
    const placement pl;
    g.add_piece(p, pl);
    assert(!g.can_add_piece(p, pl));
  }
}
