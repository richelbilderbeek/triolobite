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
     /a\
    /c b\
   *-----*
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

///Can these two pieces be connected in any way
bool can_connect(const piece& p, const piece& q) noexcept;

void test_piece();

#endif // PIECE_H
