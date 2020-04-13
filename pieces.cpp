#include "pieces.h"

#include <cassert>

pieces::pieces(std::vector<piece> ps)
  : m_pieces{ps}
{

}

std::vector<piece> create_all_pieces()
{
  std::vector<piece> pieces;
  pieces.reserve(6 * 6 * 6);
  for (int a = 0; a != 6; ++a)
  {
    for (int b = 0; b != 6; ++b)
    {
      for (int c = 0; c != 6; ++c)
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
    assert(p.size() == 6 * 6 * 6);
  }
}
