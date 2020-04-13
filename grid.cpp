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

bool is_adjacent(const placement& pl, const grid& g)
{
  assert(!is_taken(pl, g));
  const int x{get_x(pl)};
  const int y{get_y(pl)};
  //Default positioning: check right, below and left
  if ((x + y) % 2 == 0) {
    return
         is_taken(x + 1, y + 0, g)
      || is_taken(x + 0, y + 1, g)
      || is_taken(x - 1, y + 0, g)
    ;
  } else {
    //Upside-down positioning: check above, right and left
    return
         is_taken(x + 0, y - 1, g)
      || is_taken(x + 1, y + 0, g)
      || is_taken(x - 1, y + 0, g)
    ;
  }
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
  //Cannot add a piece at a taken position
  {
    const grid g = create_test_grid();
    assert(is_taken(placement(), g));
    assert(!g.can_add_piece());
  }
  //Detect which placements are adjacent from starting position
  {
    const grid g = create_test_grid();
    //Up: not adjancent, as center triangle has tip at top
    assert(!is_adjacent(placement( 0, -1, 60), g));
    //Right, below, left: all adjacent
    assert( is_adjacent(placement( 1,  0, 60), g));
    assert( is_adjacent(placement( 0,  1, 60), g));
    assert( is_adjacent(placement(-1,  0, 60), g));
  }
  //Detect which placements are adjacent from position above start
  {
    grid g;
    g.add_piece(piece(), placement(0, -1, 60));
    //Below: not adjancent, as this triangle has tip at bottom
    assert(!is_adjacent(placement( 0, 0, 120), g));
    //Above, right, left: all adjacent
    assert( is_adjacent(placement( 0, -2, 120), g));
    assert( is_adjacent(placement( 1, -1, 120), g));
    assert( is_adjacent(placement(-1, -1, 120), g));
  }
}
