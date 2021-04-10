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

} // namespace playingcards
