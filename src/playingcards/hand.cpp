// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include "hand.h"

#include <algorithm>
#include <cassert>
#include <stdexcept>

namespace playingcards {

inline constexpr std::size_t k_hand_size{5};

void Hand::AddCard(const Card::ShrPtr& card)
{
  assert(cards_.size() <= k_hand_size && "The hand is already full!");

  cards_.emplace_back(card);

  suits_.emplace(card.get()->suit);

  CountAndSortRanks(card.get()->rank);

  if (cards_.size() == k_hand_size)
    poker_combination_ = CalculatePokerCombination();
}

void Hand::CountAndSortRanks(Card::Rank rank)
{
  auto rank_count = std::find_if(
      ranks_counts_.begin(),
      ranks_counts_.end(),
      [&rank](const auto& rc) {
          return rc.first == rank;
    });

  if (rank_count == ranks_counts_.end()) {
    ranks_counts_.emplace_back(std::make_pair(rank,1));
  }
  else {
    ++rank_count->second;
  }

  std::sort(
      ranks_counts_.begin(),
      ranks_counts_.end(),
      [](const auto& left, const auto& right){
          if (left.second == right.second)
            return left.first > right.first;
          return left.second > right.second;
  });

  // If combination is "a wheel"
  if (ranks_counts_.size() == k_hand_size &&
      ranks_counts_.begin()->first == Card::Rank::Ace &&
      (ranks_counts_.begin() + 1)->first == Card::Rank::Five) {
    ranks_counts_.begin()->first = Card::Rank::One;
    std::sort(
        ranks_counts_.begin(),
        ranks_counts_.end(),
        [](const auto& left, const auto& right){
            if (left.second == right.second)
              return left.first > right.first;
            return left.second > right.second;
    });
  }
}

void Hand::Clear()
{
  cards_.clear();
  suits_.clear();
  ranks_counts_.clear();
}

PokerCombination Hand::GetPokerCombination() const
{
  assert(cards_.size() == k_hand_size && "The hand is not full!");

  return poker_combination_;
}

PokerCombination Hand::CalculatePokerCombination()
{
  assert(cards_.size() == k_hand_size && "The hand is not full!");

  bool is_flush = (suits_.size() == 1);

  std::uint16_t distance_ranks = static_cast<std::uint16_t>(ranks_counts_.begin()->first) -
      static_cast<std::uint16_t>(ranks_counts_.rbegin()->first);

  bool is_straight = (ranks_counts_.size() == k_hand_size && distance_ranks == 4);

  if (is_flush && is_straight && ranks_counts_.begin()->first == Card::Rank::Ace)
    return PokerCombination::RoyalFlush;

  if (is_flush && is_straight)
    return PokerCombination::StraightFlush;

  if (ranks_counts_.begin()->second == 4)
    return PokerCombination::FourOfAKind;

  if (ranks_counts_.begin()->second == 3 && ranks_counts_.rbegin()->second == 2)
    return PokerCombination::FullHouse;

  if (is_flush)
    return PokerCombination::Flush;

  if (is_straight)
    return PokerCombination::Straight;

  if (ranks_counts_.begin()->second == 3)
    return PokerCombination::ThreeOfAKind;

  if (ranks_counts_.begin()->second == 2 && ranks_counts_.size() == 3)
    return PokerCombination::TwoPairs;

  if (ranks_counts_.begin()->second == 2)
    return PokerCombination::OnePair;

  return PokerCombination::HighCard;
}

bool operator<(const Hand& left, const Hand& right)
{
  assert(left.cards_.size() == k_hand_size &&
      right.cards_.size() == k_hand_size &&
          "Left or right hand is not full!");

  if (left.poker_combination_ < right.poker_combination_)
    return true;

  bool is_less = false;

  if (left.poker_combination_ == right.poker_combination_) {
    auto mismatch_rank_count = std::mismatch(left.ranks_counts_.begin(),
        left.ranks_counts_.end(),right.ranks_counts_.begin());

    if (mismatch_rank_count.first != left.ranks_counts_.end() &&
        mismatch_rank_count.second != right.ranks_counts_.end()) {
      if (*mismatch_rank_count.first < *mismatch_rank_count.second)
        is_less = true;
    }
  }

  return is_less;
}

bool operator>(const Hand& left, const Hand& right)
{
  return right < left;
}

bool operator==(const Hand& left, const Hand& right)
{
  return !(left < right) && !(left > right);
}

} // namespace playingcards
