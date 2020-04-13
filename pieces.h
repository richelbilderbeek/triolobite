#ifndef PIECES_H
#define PIECES_H

#include "piece.h"
#include <vector>

///A collection of pieces
class pieces
{
public:
  pieces(std::vector<piece> ps = {});

  int size() const noexcept;

private:

  std::vector<piece> m_pieces;
};

///Create all pieces
std::vector<piece> create_all_pieces();

void test_pieces();

#endif // PIECES_H
