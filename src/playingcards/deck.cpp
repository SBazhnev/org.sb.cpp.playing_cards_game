// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "deck.h"

#include <algorithm>
#include <random>
#include <stdexcept>

namespace playingcards {

Deck::Deck(DeckSize size) :
    size_{size},
    container_{},
    top_card_{nullptr}
{
  Generate();
  Shuffle();
}

void Deck::Shuffle()
{
  if (!container_.empty()) {
    std::random_device random_device;
    std::mt19937 generator{random_device()};

    for (std::uint16_t i = 0; i < static_cast<std::uint16_t>(size_); ++i) {
      std::shuffle(container_.begin(),container_.end(),generator);
    }

    top_card_ = container_.begin();
  }
}

Card::ShrPtr Deck::PopTopCard()
{
  if (container_.empty())
    throw std::runtime_error("The deck is empty!");

  if (top_card_ == container_.end())
    throw std::runtime_error("The cards are over!");

  return *(top_card_)++;
}

void Deck::Generate()
{
  container_.clear();

  auto start_rank = std::find(k_card_ranks.begin(),k_card_ranks.end(),
      (size_ == DeckSize::Cards36) ? CardRank::Six : CardRank::Two);

  for (auto& suit : k_card_suits) {
    for (auto& rank = start_rank; rank < k_card_ranks.end(); ++rank) {
      container_.emplace_back(std::make_shared<Card>(suit,*rank));
    }
  }

  // TODO add two Jokers if deck_size_ == DeckSize::Cards54

  top_card_ = container_.begin();
}

} // namespace playingcards
