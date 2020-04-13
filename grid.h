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
    piece& p,
    const placement& pl
  );

  /// Get all pieces
  const auto& get_pieces() const noexcept { return m_pieces; }

private:

  std::vector<std::pair<piece, placement>> m_pieces;
};

int count_pieces(const grid& g) noexcept;

void test_grid();

#endif // GRID_H
