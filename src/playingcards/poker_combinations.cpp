// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include "playingcards/poker_combinations.h"

namespace playingcards {

std::string GetPokerCombinationText(PokerCombination poker_combination)
{
  if (poker_combination == PokerCombination::HighCard)
    return "high card";

  if (poker_combination == PokerCombination::OnePair)
    return "one pair";

  if (poker_combination == PokerCombination::TwoPairs)
    return "two pairs";

  if (poker_combination == PokerCombination::ThreeOfAKind)
    return "three of a kind";

  if (poker_combination == PokerCombination::Straight)
    return "straight";

  if (poker_combination == PokerCombination::Flush)
    return "flush";

  if (poker_combination == PokerCombination::FullHouse)
    return "full house";

  if (poker_combination == PokerCombination::FourOfAKind)
    return "four of a kind";

  if (poker_combination == PokerCombination::StraightFlush)
    return "straight flush";

  if (poker_combination == PokerCombination::RoyalFlush)
    return "royal flush";

  return std::string();
}

} // namespace playingcards
