#include "placement.h"
#include <cassert>

placement::placement(
  const int x,
  const int y,
  const int angle
) : m_angle{angle}, m_x{x}, m_y{y}
{
  assert(is_angle(angle));
  assert(has_correct_angle(m_x, m_y, m_angle));
}

int get_angle(const placement& p) noexcept
{
  return p.get_angle();
}

int get_x(const placement& p) noexcept
{
  return p.get_x();
}

int get_y(const placement& p) noexcept
{
  return p.get_y();
}

bool has_correct_angle(const int x, const int y, const int angle)
{
  assert(is_angle(angle));
  return (x + y) % 2 == 0 && angle % 120 == 0;
}

void test_placement()
{
  // A default placement
  {
    const placement p;
    assert(get_x(p) == 0);
  }
  // Correct angles at starting position at 0, 120, 240
  {
    assert( has_correct_angle(0, 0,   0));
    assert(!has_correct_angle(0, 0,  60));
    assert( has_correct_angle(0, 0, 120));
    assert(!has_correct_angle(0, 0, 180));
    assert( has_correct_angle(0, 0, 240));
    assert(!has_correct_angle(0, 0, 300));
  }
  // Setters and getters must be symmetrical
  {
    const int x{1};
    const int y{3};
    const int angle{120};
    const placement p(x, y, angle);
    assert(get_x(p) == x);
    assert(get_y(p) == y);
    assert(get_angle(p) == angle);
  }
}
