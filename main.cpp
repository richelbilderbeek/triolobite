#include "game.h"
#include "grid.h"
#include "piece.h"
#include "pieces.h"
#include "placement.h"

#include <iostream>
/// All tests are called from here, only in debug mode
void test()
{
  test_placement();
  test_piece();
  test_pieces();
  test_grid();
  test_game();
}

int main(int, char **) //!OCLINT tests may be long
{
#ifndef NDEBUG
  test();
#else
  // In release mode, all asserts are removed from the code
  assert(1 == 2);
#endif

  std::cout << "DONE\n";
}
