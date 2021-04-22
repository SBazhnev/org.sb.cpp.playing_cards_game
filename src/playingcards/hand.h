// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
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
    cards_container_{},
    poker_combination_{PokerCombination::HighCard},
    suits_on_hand_{},
    ranks_counts_on_hand_{}
  {
  };

  ~Hand() = default;

  Hand(const Hand&) = default;
  Hand(Hand&&) = default;

  Hand& operator=(const Hand&) = default;
  Hand& operator=(Hand&&) = default;

  void AddCard(const Card::ShrPtr& card);

  void Clear();

  const CardsContainer& GetCards() const
  {
    return cards_container_;
  }

  PokerCombination GetPokerCombination() const;
  
  friend bool operator<(const Hand&, const Hand&);
  friend bool operator>(const Hand&, const Hand&);
  friend bool operator==(const Hand&, const Hand&);

private:
  // Count the number of ranks in the hand and then sort it
  // first by number then by rank
  void CountAndSortRanks(CardRank rank);

  PokerCombination CalculatePokerCombination();

private:
  CardsContainer cards_container_;

  PokerCombination poker_combination_;

  // For counting the number of different suits in the hand
  std::set<CardSuit> suits_on_hand_;

  // For counting the number of different ranks in the hand
  std::vector<std::pair<CardRank,std::size_t>> ranks_counts_on_hand_;

};

} // namespace playingcards

#endif // PLAYINGCARDS_HAND_H_
