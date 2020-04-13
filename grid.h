#ifndef GRID_H
#define GRID_H

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

  |     |     |     |     |     |
 -+........*..*-----*..*.........-
  .     . /2\ .\2 1/. /1\ .     .
  .     ./1 3\. \3/ ./3 2\.     .
 -...*..*-----*  *  *-----*..*...-
  . /1\ .\1 3/. /3\ .\3 2/. /2\ .
  ./3 2\. \2/ ./2 1\. \1/ ./1 3\.
 -*-----*..*..*-----*..*..*-----*-
  |     |     |     |     |     |

*/
class grid
{
public:
  grid();
};

int count_pieces(const grid& g) noexcept;

void test_grid();

#endif // GRID_H
