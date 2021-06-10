// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include "card.h"

namespace playingcards {

const std::vector<Card::Suit> k_card_suits_store{
  Card::Suit::Clubs,
  Card::Suit::Spades,
  Card::Suit::Diamonds,
  Card::Suit::Hearts
};

const std::vector<Card::Rank> k_card_ranks_store{
  Card::Rank::Two,
  Card::Rank::Three,
  Card::Rank::Four,
  Card::Rank::Five,
  Card::Rank::Six,
  Card::Rank::Seven,
  Card::Rank::Eight,
  Card::Rank::Nine,
  Card::Rank::Ten,
  Card::Rank::Jack,
  Card::Rank::Queen,
  Card::Rank::King,
  Card::Rank::Ace
};

std::string GetCardSuitText(Card::Suit suit)
{
  if (suit == Card::Suit::Clubs)
    return "clubs";

  if (suit == Card::Suit::Spades)
    return "spades";

  if (suit == Card::Suit::Diamonds)
    return "diamonds";

  if (suit == Card::Suit::Hearts)
    return "hearts";

  return std::string();
}

std::string GetCardRankText(Card::Rank rank)
{
  if (rank == Card::Rank::One)
    return "one";

  if (rank == Card::Rank::Two)
    return "two";

  if (rank == Card::Rank::Three)
    return "three";

  if (rank == Card::Rank::Four)
    return "four";

  if (rank == Card::Rank::Five)
    return "five";

  if (rank == Card::Rank::Six)
    return "six";

  if (rank == Card::Rank::Seven)
    return "seven";

  if (rank == Card::Rank::Eight)
    return "eight";

  if (rank == Card::Rank::Nine)
    return "nine";

  if (rank == Card::Rank::Ten)
    return "ten";

  if (rank == Card::Rank::Jack)
    return "jack";

  if (rank == Card::Rank::Queen)
    return "queen";

  if (rank == Card::Rank::King)
    return "king";

  if (rank == Card::Rank::Ace)
    return "ace";

  return std::string();
}

} // namespace playingcards
