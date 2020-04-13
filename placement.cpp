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

void test_placement()
{

}
