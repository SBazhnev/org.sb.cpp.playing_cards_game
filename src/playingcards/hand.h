// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef PLAYINGCARDS_HAND_H_
#define PLAYINGCARDS_HAND_H_

#include <memory>
#include <set>
#include <vector>

#include "playingcards/card.h"
#include "playingcards/poker_combinations.h"

namespace playingcards {

class Hand {
public:
  using ShrPtr = std::shared_ptr<Hand>;

  Hand() :
    cards_{},
    poker_combination_{PokerCombination::HighCard},
    suits_{},
    ranks_counts_{}
  {
  };

  ~Hand() = default;

  Hand(const Hand&) = default;
  Hand(Hand&&) = default;

  Hand& operator=(const Hand&) = default;
  Hand& operator=(Hand&&) = default;

  void AddCard(const Card::ShrPtr& card);

  void Clear();

  const CardsStore& GetCards() const
  {
    return cards_;
  }

  PokerCombination GetPokerCombination() const;
  
  friend bool operator<(const Hand&, const Hand&);
  friend bool operator>(const Hand&, const Hand&);
  friend bool operator==(const Hand&, const Hand&);

private:
  // Count the number of ranks in the hand and then sort it
  // first by number then by rank
  void CountAndSortRanks(Card::Rank rank);

  PokerCombination CalculatePokerCombination();

private:
  CardsStore cards_;

  PokerCombination poker_combination_;

  // For counting the number of different suits in the hand
  std::set<Card::Suit> suits_;

  // For counting the number of different ranks in the hand
  std::vector<std::pair<Card::Rank,std::size_t>> ranks_counts_;

};

} // namespace playingcards

#endif // PLAYINGCARDS_HAND_H_
