#include "grid.h"
#include <cassert>

grid::grid()
{

}

void grid::add_piece(
  piece& p,
  const placement& pl
)
{
  m_pieces.push_back(std::make_pair(p, pl));
}

int count_pieces(const grid& g) noexcept
{
  return static_cast<int>(g.get_pieces().size());
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
    piece p;
    g.add_piece(p, placement());
    assert(count_pieces(g) == 1);
  }

}
