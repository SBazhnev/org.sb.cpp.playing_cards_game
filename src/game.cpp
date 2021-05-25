// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "game.h"

#include <iostream>
#include <stdexcept>

#include "playingcards/deck.h"
#include "playingcards/hand.h"

using namespace ui::console;
using namespace ui::console::playingcards;

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
  catch (...) { // TODO move to main()
    std::cout << "Unknown error! Exit." << "\n";
  }
}

void Game::Run()
{
  MenuOptionHandlerType exit_handler = std::bind(&Game::Exit,this);
  MenuOptionHandlerType simple_mode_handler = std::bind(&Game::ModeSimpleRun,this);
  MenuOptionHandlerType two_players_mode_handler = std::bind(&Game::ModeTwoPlayersRun,this);

  game_view_.Create(exit_handler,simple_mode_handler,two_players_mode_handler,std::cin);

  ShowGameView();
}

void Game::ModeSimpleRun()
{
  Deck deck{};

  deck.Shuffle();

  auto hand = std::make_shared<Hand>();

  for (std::size_t i = 0; i < 5; ++i) {
    hand->AddCard(deck.PopTopCard());
  }

  game_view_.SetGameTableSimpleMode(hand);

  ShowGameView();
}

void Game::ModeTwoPlayersRun()
{
  game_view_.SetStatusLabelText(k_two_players_mode_menu_option_text);

  ShowGameView();
}

void Game::Exit()
{
  std::cout << "Exit \n";
}

} // namespace playingcards
