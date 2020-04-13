#include "placement.h"
#include <cassert>

placement::placement(
  const int x,
  const int y,
  const int angle
) : m_angle{angle}, m_x{x}, m_y{y}
{
  assert(is_angle(angle));
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

void test_placement()
{

}
