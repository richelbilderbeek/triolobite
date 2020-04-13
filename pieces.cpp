#include "pieces.h"

#include <cassert>

pieces::pieces(std::vector<piece> ps)
  : m_pieces{ps}
{

}

std::vector<piece> create_all_pieces()
{
  std::vector<piece> pieces;
  pieces.reserve(get_total_n_pieces());
  for (int a = 0; a != 6; ++a)
  {
    for (int b = a; b != 6; ++b)
    {
      for (int c = b; c != 6; ++c)
      {
        pieces.push_back(piece(a, b, c));
      }
    }
  }
  return pieces;
}

int pieces::size() const noexcept
{
  return static_cast<int>(m_pieces.size());
}

void test_pieces()
{
  //Correct number of pieces
  {
    const auto p = create_all_pieces();
    assert(static_cast<int>(p.size()) == get_total_n_pieces());
  }
}
