// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef GAME_H_
#define GAME_H_

#include "ui/console/game_view.h"

namespace playingcards {

class Game {
public:
  Game() : game_view_{}
  {
  }

  ~Game() = default;

  Game(const Game&) = default;
  Game& operator=(const Game&) = default;

  Game(Game&&) = default;
  Game& operator=(Game&&) = default;

  void Run();

private:
  void ShowGameView();

  void ModeSimpleRun();
  void ModeTwoPlayersRun();
  void Exit();

private:
  ui::console::playingcards::GameView game_view_;

};

} // namespace playingcards

#endif // GAME_H_
