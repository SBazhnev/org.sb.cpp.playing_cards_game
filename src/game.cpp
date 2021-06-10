// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include "game.h"

#include <memory>
#include <stdexcept>
#include <string_view>

#include "player.h"
#include "playingcards/hand.h"

using namespace ui::console;
using namespace ui::console::playingcards;

namespace playingcards {

// TODO move to localization file
constexpr std::string_view k_player_1_name = "You";
constexpr std::string_view k_player_2_name = "Comp";

Game::Game(std::ostream& out, std::istream& in) :
    out_{&out},
    in_{&in},
    game_view_{std::make_unique<GameView>()},
    deck_{std::make_unique<Deck>()}
{
}

void Game::Run()
{
  Configure();

  ShowGameView();
}

void Game::Configure()
{
  MenuOption::HandlerType exit_handler = std::bind(&Game::Exit,this);
  MenuOption::HandlerType simple_mode_handler = std::bind(&Game::ModeSimpleRun,this);
  MenuOption::HandlerType two_players_mode_handler = std::bind(&Game::ModeTwoPlayersRun,this);

  game_view_->BuildMainFrame(exit_handler,simple_mode_handler,two_players_mode_handler,*in_);
}

void Game::ShowGameView()
{
  try {
    *out_ << '\n' << *game_view_;
  }
  catch (std::exception& e) {
    game_view_->SetStatusLabelText(e.what());

    ShowGameView();
  }
}

void Game::ModeSimpleRun()
{
  deck_->Shuffle();

  auto hand = std::make_shared<Hand>();

  for (std::size_t i = 0; i < 5; ++i) {
    hand->AddCard(deck_->PopTopCard());
  }

  game_view_->SetGameTableSimpleMode(hand);

  ShowGameView();
}

void Game::ModeTwoPlayersRun()
{
  deck_->Shuffle();

  auto player_1_hand = std::make_shared<Hand>();
  auto player_2_hand = std::make_shared<Hand>();

  for (std::size_t i = 0; i < 5; ++i) {
    // TODO implement random order card deal
    player_1_hand->AddCard(deck_->PopTopCard());
    player_2_hand->AddCard(deck_->PopTopCard());
  }

  Player player_1{k_player_1_name,player_1_hand};
  Player player_2{k_player_2_name,player_2_hand};

  game_view_->SetGameTableTwoPlayersMode(player_1,player_2);

  ShowGameView();
}

void Game::Exit()
{
  game_view_->SetExitFrame();

  ShowGameView();
}

} // namespace playingcards
