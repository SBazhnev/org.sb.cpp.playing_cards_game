// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef PLAYINGCARDS_POKER_COMBINATIONS_H_
#define PLAYINGCARDS_POKER_COMBINATIONS_H_

#include <cstdint>
#include <string>

namespace playingcards {

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

std::string GetPokerCombinationText(PokerCombination poker_combination);

} // namespace playingcards

#endif // PLAYINGCARDS_POKER_COMBINATIONS_H_
