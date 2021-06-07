// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef PLAYINGCARDS_DECK_H_
#define PLAYINGCARDS_DECK_H_

#include <cstdint>
#include <memory>
#include <vector>

#include "playingcards/card.h"

namespace playingcards {

enum class DeckSize : std::size_t {
  Cards36 = 36, // from Six to Ace
  Cards52 = 52, // from Two to Ace
  Cards54 = 54  // from Two to Ace + 2 Jokers
};

class Deck {
public:
  using ShrPtr = std::shared_ptr<Deck>;
  using WeakPtr = std::weak_ptr<Deck>;
  using UnqPtr = std::unique_ptr<Deck>;

  explicit Deck(DeckSize size = DeckSize::Cards52);

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
  Card::ShrPtr PopTopCard();

private:
  // Create deck
  void Generate();

private:
  DeckSize size_;

  CardsContainer container_;

  // The deal of cards is simulated using
  // a pointer to the current container element
  CardsContainer::iterator top_card_;

};

} // namespace playingcards

#endif // PLAYINGCARDS_DECK_H_
