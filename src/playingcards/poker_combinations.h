// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef PLAYINGCARDS_POKER_COMBINATIONS_H_
#define PLAYINGCARDS_POKER_COMBINATIONS_H_

#include <cstdint>

enum class PokerCombination : std::uint16_t {
  HighCard,
  OnePair,
  TwoPairs,
  ThreeOfAKind,
  Straight,
  Flush,
  FullHouse,
  FourOfAKind,
  StraightFlush,
  RoyalFlush
};

#endif // PLAYINGCARDS_POKER_COMBINATIONS_H_
