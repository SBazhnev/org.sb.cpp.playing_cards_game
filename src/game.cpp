// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "game.h"

#include <iostream>

#include "ui/console/game_view.h"

namespace playingcards {

void Game::Run()
{
  ui::console::playingcards::GameView game_view{};

  ui::console::MenuOptionHandlerType exit_handler = std::bind(&Game::Exit,this);
  ui::console::MenuOptionHandlerType simple_mode_handler = std::bind(&Game::ModeSimpleRun,this);
  ui::console::MenuOptionHandlerType two_players_mode_handler = std::bind(&Game::ModeTwoPlayersRun,this);

  game_view.Create(exit_handler,simple_mode_handler,two_players_mode_handler,std::cin);

  std::cout << game_view;
}

void Game::ModeSimpleRun()
{
  std::cout << "Simple mode \n";
}

void Game::ModeTwoPlayersRun()
{
  std::cout << "Two players mode \n";
}

void Game::Exit()
{
  std::cout << "Exit \n";
}

} // namespace playingcards
