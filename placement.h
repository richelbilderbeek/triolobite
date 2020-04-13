#ifndef PLACEMENT_H
#define PLACEMENT_H

/// The placement of a piece
class placement
{
public:
  placement(
    const int x = 0,
    const int y = 0,
    const int angle = 0
  );

  int get_angle() const noexcept { return m_angle; }
  int get_x() const noexcept { return m_x; }
  int get_y() const noexcept { return m_y; }

private:

  int m_angle;
  int m_x;
  int m_y;
};

int get_angle(const placement& p) noexcept;
int get_x(const placement& p) noexcept;
int get_y(const placement& p) noexcept;

/// Determine if an angle is valid
constexpr bool is_angle(const int angle) noexcept{
  return angle == 0
    || angle == 60
    || angle == 120
    || angle == 180
    || angle == 240
    || angle == 300
  ;
}

void test_placement();

#endif // PLACEMENT_H
