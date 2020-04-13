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

/// Get the total number of pieces in the game
constexpr int get_total_n_pieces() noexcept { return 56; }

///Create all pieces
std::vector<piece> create_all_pieces();

void test_pieces();

#endif // PIECES_H
