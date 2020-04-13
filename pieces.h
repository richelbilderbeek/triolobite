#ifndef PIECES_H
#define PIECES_H

#include "piece.h"
#include <vector>

///All pieces
class pieces
{
public:
  pieces();

  int size() const noexcept;

private:

  std::vector<piece> m_pieces;
};

///Create the pieces
std::vector<piece> create_pieces();

void test_pieces();

#endif // PIECES_H
