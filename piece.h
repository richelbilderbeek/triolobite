#ifndef PIECE_H
#define PIECE_H


///A Triominos piece
/*
    *
   /a\
  /c b\
 *-----*
*/
class piece
{
public:
  ///Create a piece from its three values.
  /*
      *
    C/1\A
    /3 2\
   *-----*
      B
  */
  /// @param top top value
  /// @param bottom_right bottom-right value
  /// @param bottom_left bottom-left value
  piece(
    const int top = 0,
    const int bottom_right = 0,
    const int bottom_left = 0
  );

  /// Get value at top
  int get_top() const noexcept { return m_top; }
  /// Get value at bottom-right
  int get_bottom_right() const noexcept { return m_bottom_right; }
  /// Get value at bottom-left
  int get_bottom_left() const noexcept { return m_bottom_left; }

  private:
  int m_top;
  int m_bottom_right;
  int m_bottom_left;

};

/// Get the ID of the edge between top and bottom-right value
int get_a(const piece& p) noexcept;

/// Get the ID of the edge between bottom-right and bottom-left value
int get_b(const piece& p) noexcept;

/// Get the ID of the edge between bottom-left and top value
int get_c(const piece& p) noexcept;

///Can these two pieces be connected in any way
bool can_connect(const piece& p, const piece& q) noexcept;

void test_piece();

#endif // PIECE_H
