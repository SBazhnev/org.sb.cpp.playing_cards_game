// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "game.h"

#include <iostream>
#include <stdexcept>

namespace playingcards {

void Game::ShowGameView()
{
  try {
    std::cout << '\n' << game_view_;
  }
  catch (std::exception& e) {
    game_view_.SetStatusLabelText(e.what());

    ShowGameView();
  }
  catch (...) {
    std::cout << "Unknown error! Exit." << "\n";
  }
}

void Game::Run()
{
  ui::console::MenuOptionHandlerType exit_handler = std::bind(&Game::Exit,this);
  ui::console::MenuOptionHandlerType simple_mode_handler = std::bind(&Game::ModeSimpleRun,this);
  ui::console::MenuOptionHandlerType two_players_mode_handler = std::bind(&Game::ModeTwoPlayersRun,this);

  game_view_.Create(exit_handler,simple_mode_handler,two_players_mode_handler,std::cin);

  ShowGameView();
}

void Game::ModeSimpleRun()
{
  game_view_.SetStatusLabelText("Simple mode");

  ShowGameView();
}

void Game::ModeTwoPlayersRun()
{
  game_view_.SetStatusLabelText("Two players mode");

  ShowGameView();
}

void Game::Exit()
{
  std::cout << "Exit \n";
}

} // namespace playingcards
