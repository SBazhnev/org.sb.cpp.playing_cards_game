// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef PLAYINGCARDS_CARD_H_
#define PLAYINGCARDS_CARD_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace playingcards {

enum class CardSuit : std::uint16_t {
  Clubs, Spades, Diamonds, Hearts
};

enum class CardRank : std::uint16_t {
  One = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

extern const std::vector<CardSuit> k_card_suits;

extern const std::vector<CardRank> k_card_ranks;

std::string GetCardSuitText(const CardSuit& suit);

std::string GetCardRankText(const CardRank& rank);

struct Card {
  using ShrPtr = std::shared_ptr<Card>;

  CardSuit suit;
  CardRank rank;

  explicit Card(CardSuit s, CardRank r) : suit{s}, rank{r}
  {
  }

  ~Card() = default;

  Card(const Card&) = default;
  Card(Card&&) = default;

  Card& operator=(const Card&) = default;
  Card& operator=(Card&&) = default;

};

using CardsContainer = std::vector<Card::ShrPtr>;

} // namespace playingcards

#endif // PLAYINGCARDS_CARD_H_
