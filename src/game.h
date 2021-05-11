// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef GAME_H_
#define GAME_H_

namespace playingcards {

class Game {
public:
  Game() = default;

  ~Game() = default;

  Game(const Game&) = default;
  Game& operator=(const Game&) = default;

  Game(Game&&) = default;
  Game& operator=(Game&&) = default;

  void Run();

private:
  void ModeSimpleRun();
  void ModeTwoPlayersRun();
  void Exit();

  void InputHandler(unsigned short index);

};

} // namespace playingcards

#endif // GAME_H_
