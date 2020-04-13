#include "piece.h"

#include <cassert>

piece::piece(
  const int top,
  const int bottom_right,
  const int bottom_left
) : m_top{top},
    m_bottom_right{bottom_right},
    m_bottom_left{bottom_left}
{
  assert(m_top >= 0 && m_top <= 5);
  assert(m_bottom_left >= 0 && m_bottom_left <= 5);
  assert(m_bottom_right >= 0 && m_bottom_right <= 5);
}

bool can_connect(const piece&, const piece&) noexcept
{
  return false;
}

void test_piece()
{
  //A piece has three zeroes by default
  {
    const piece p;
    assert(p.get_top() == 0);
    assert(p.get_bottom_right() == 0);
    assert(p.get_bottom_left() == 0);
  }
  //Getters work correctly
  {
    const int top{1};
    const int bottom_right{2};
    const int bottom_left{3};
    const piece p(top, bottom_right, bottom_left);
    assert(p.get_top() == top);
    assert(p.get_bottom_right() == bottom_right);
    assert(p.get_bottom_left() == bottom_left);
  }
  //Cannot connect 000 with 111
  {
    const piece p(0, 0, 0);
    const piece q(0, 0, 0);
    assert(!can_connect(p, q));
  }
}
