// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef PLAYINGCARDS_CARD_H_
#define PLAYINGCARDS_CARD_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace playingcards {

struct Card {
  using ShrPtr = std::shared_ptr<Card>;
  using UnqPtr = std::unique_ptr<Card>;

  enum class Suit : std::uint16_t {
    Clubs, Spades, Diamonds, Hearts
  };

  enum class Rank : std::uint16_t {
    One = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
  };

  Suit suit;
  Rank rank;

  explicit Card(Suit suit_, Rank rank_) : suit{suit_}, rank{rank_}
  {
  }

  ~Card() = default;

  Card(const Card&) = default;
  Card& operator=(const Card&) = default;

  Card(Card&&) = default;
  Card& operator=(Card&&) = default;

};

using CardsStore = std::vector<Card::ShrPtr>;

// For support deck generation
extern const std::vector<Card::Suit> k_card_suits_store;
extern const std::vector<Card::Rank> k_card_ranks_store;

std::string GetCardSuitText(Card::Suit suit);
std::string GetCardRankText(Card::Rank rank);

} // namespace playingcards

#endif // PLAYINGCARDS_CARD_H_
