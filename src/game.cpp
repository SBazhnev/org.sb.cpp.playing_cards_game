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

  ui::console::InputHandler input_handler = std::bind(&Game::InputHandler,this,std::placeholders::_1);

  game_view.Create(exit_handler,simple_mode_handler,two_players_mode_handler,input_handler,std::cin);

  std::cout << game_view;
}

void Game::ModeSimpleRun()
{
}

void Game::ModeTwoPlayersRun()
{
}

void Game::Exit()
{
}

void Game::InputHandler(unsigned short index)
{
}

} // namespace playingcards
