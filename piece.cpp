#include "piece.h"

#include <algorithm>
#include <cassert>
#include <set>

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

bool can_connect(const piece& p, const piece& q) noexcept
{
  //Can connect if there is an ID that is not unique
  //between the two pieces.
  //So, if there is no intersect between the two sets,
  //all values are unique, thus cannot connect
  //sum of the two sets
  const std::set<int> a = {
    p.get_top(),
    p.get_bottom_right(),
    p.get_bottom_left()
  };
  const std::set<int> b = {
    q.get_top(),
    q.get_bottom_right(),
    q.get_bottom_left()
  };
  std::set<int> c;
  std::set_intersection(
    std::begin(a),
    std::end(a),
    std::begin(b),
    std::end(b),
    std::inserter(c, std::begin(c))
  );
  return !c.empty();
}

int get_a(const piece& p) noexcept
{
  return (p.get_top() * 10) + p.get_bottom_right();
}

int get_b(const piece& p) noexcept
{
  return (p.get_bottom_right() * 10) + p.get_bottom_left();
}

int get_c(const piece& p) noexcept
{
  return (p.get_bottom_left() * 10) + p.get_top();
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
  //IDs work correctly
  {
    /*
        *
      C/1\A
      /3 2\
     *-----*
        B
    */
    const piece p(1, 2, 3);
    assert(get_a(p) == 12);
    assert(get_b(p) == 23);
    assert(get_c(p) == 31);
  }
  //Cannot connect 000 with 111
  {
    const piece p(0, 0, 0);
    const piece q(1, 1, 1);
    assert(!can_connect(p, q));
  }
  //Can connect 123 with 132
  /*
        *-----*
       /2\2 1/1\
      /1 3\3/3 2\
     *-----*-----*
    /1\1 3/3\3 2/2\
   /3 2\2/2 1\1/1 3\
  *-----*--- -*-----*

  */
  {
    const piece p(1, 2, 3);
    const piece q(1, 3, 2);
    assert(can_connect(p, q));
  }
}
