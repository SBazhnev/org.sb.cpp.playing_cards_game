// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "playingcards/deck.h"

#include "ui/console/game_view.h"

namespace playingcards {

class Game {
public:
  explicit Game(std::ostream& out = std::cout, std::istream& in = std::cin);

  ~Game() = default;

  Game(const Game&) = default;
  Game& operator=(const Game&) = default;

  Game(Game&&) = default;
  Game& operator=(Game&&) = default;

  void Run();

private:
  void Configure();

  void ShowGameView();

  void ModeSimpleRun();
  void ModeTwoPlayersRun();
  void Exit();

private:
  std::ostream* out_;
  std::istream* in_;

  ui::console::playingcards::GameView::UnqPtr game_view_;

  Deck::UnqPtr deck_;

};

} // namespace playingcards

#endif // GAME_H_
