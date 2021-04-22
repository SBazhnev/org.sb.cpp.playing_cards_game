// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "card.h"

namespace playingcards {

const std::vector<CardSuit> k_card_suits{
  CardSuit::Clubs,
  CardSuit::Spades,
  CardSuit::Diamonds,
  CardSuit::Hearts
};

const std::vector<CardRank> k_card_ranks{
  CardRank::Two,
  CardRank::Three,
  CardRank::Four,
  CardRank::Five,
  CardRank::Six,
  CardRank::Seven,
  CardRank::Eight,
  CardRank::Nine,
  CardRank::Ten,
  CardRank::Jack,
  CardRank::Queen,
  CardRank::King,
  CardRank::Ace
};

std::string GetCardSuitText(const CardSuit& suit)
{
  if (suit == CardSuit::Clubs)
    return "clubs";

  if (suit == CardSuit::Spades)
    return "spades";

  if (suit == CardSuit::Diamonds)
    return "diamonds";

  if (suit == CardSuit::Hearts)
    return "hearts";

  return std::string();
}

std::string GetCardRankText(const CardRank& rank)
{
  if (rank == CardRank::One)
    return "one";

  if (rank == CardRank::Two)
    return "two";

  if (rank == CardRank::Three)
    return "three";

  if (rank == CardRank::Four)
    return "four";

  if (rank == CardRank::Five)
    return "five";

  if (rank == CardRank::Six)
    return "six";

  if (rank == CardRank::Seven)
    return "seven";

  if (rank == CardRank::Eight)
    return "eight";

  if (rank == CardRank::Nine)
    return "nine";

  if (rank == CardRank::Ten)
    return "ten";

  if (rank == CardRank::Jack)
    return "jack";

  if (rank == CardRank::Queen)
    return "queen";

  if (rank == CardRank::King)
    return "king";

  if (rank == CardRank::Ace)
    return "ace";

  return std::string();
}

} // namespace playingcards
