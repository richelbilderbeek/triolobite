#ifndef GRID_H
#define GRID_H

#include "pieces.h"
#include "placement.h"

///The triangular grid of pieces
/*

This how it looks like real life:

      *-----*
     /2\2 1/1\
    /1 3\3/3 2\
   *-----*-----*
  /1\1 3/3\3 2/2\
 /3 2\2/2 1\1/1 3\
*-----*--- -*-----*

This how it is stored in the grid:


  |  0  |  1  |  2  |  3  |  4  | X coordinat
--+........*..*-----*..*.........-
0 .     . /2\ .\2 1/. /1\ .     .
  .     ./1 3\. \3/ ./3 2\.     .
--...*..*-----*  *  *-----*..*...-
1 . /1\ .\1 3/. /3\ .\3 2/. /2\ .
  ./3 2\. \2/ ./2 1\. \1/ ./1 3\.
 -*-----*..*..*-----*..*..*-----*-
  |     |     |     |     |     |
^
+---- Y coordinat

*/
class grid
{
public:
  grid();

  /// Place a piece
  void add_piece(
    const piece& p = piece(),
    const placement& pl = placement()
  );

  /// Can a piece be placed at that location?
  bool can_add_piece(
    const piece& p = piece(),
    const placement& pl = placement()
  ) const;

  /// Get all pieces
  const auto& get_pieces() const noexcept { return m_pieces; }

private:

  std::vector<std::pair<piece, placement>> m_pieces;
};

int count_pieces(const grid& g) noexcept;

/// Is the location already taken?
/// Returns true if there is already a piece at that location
bool is_taken(const placement& pl, const grid& g);
bool is_taken(const int x, const int y, const grid& g);

void test_grid();

#endif // GRID_H
