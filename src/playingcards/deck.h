// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef PLAYINGCARDS_DECK_H_
#define PLAYINGCARDS_DECK_H_

#include <memory>
#include <vector>

#include "playingcards/card.h"

namespace playingcards {

class Deck {
public:
  using ShrPtr = std::shared_ptr<Deck>;
  using WeakPtr = std::weak_ptr<Deck>;
  using UnqPtr = std::unique_ptr<Deck>;

  enum class Size : std::size_t {
    Cards36 = 36, // from Six to Ace
    Cards52 = 52, // from Two to Ace
    Cards54 = 54  // from Two to Ace + 2 Jokers
  };

  explicit Deck(Deck::Size size = Deck::Size::Cards52);

  ~Deck() = default;

  Deck(const Deck&) = default;
  Deck(Deck&&) = default;

  Deck& operator=(const Deck&) = default;
  Deck& operator=(Deck&&) = default;

  // Shuffle cards and set the pointer of the top card to
  // the beginning of the container
  void Shuffle();

  // Return the current top card and set the next element of
  // the container as the top card
  const Card::ShrPtr& PopTopCard();

private:
  // Create deck
  void Generate();

private:
  Deck::Size size_;

  CardsStore container_;

  // The deal of cards is simulated using
  // a pointer to the current container element
  CardsStore::iterator top_card_;

};

} // namespace playingcards

#endif // PLAYINGCARDS_DECK_H_
