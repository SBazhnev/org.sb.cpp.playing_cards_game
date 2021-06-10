// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "ui/console/game_view.h"

#include <memory>

#include "playingcards/poker_combinations.h"

#include "ui/console/cards_hand_view.h"
#include "ui/console/menu.h"

namespace ui {
namespace console {
namespace playingcards {

// TODO apply std::format
// TODO move to localization file
constexpr std::string_view k_title_text = "The Simple Playing Cards game.";

constexpr std::string_view k_exit_menu_option_text = "Exit";
constexpr std::string_view k_simple_mode_menu_option_text = "Simple mode";
constexpr std::string_view k_two_players_mode_menu_option_text = "Two players mode";

constexpr std::string_view k_simple_mode_player_title_text = "Your cards:";

const     std::string      k_combination_prefix_text = "Combination: ";

const     std::string      k_winner_prefix_text = "Winner: ";

constexpr std::string_view k_draw_text = "draw!";

constexpr std::string_view k_exit_message_text = "Exit. Bye!";

void GameView::BuildMainFrame(const MenuOption::HandlerType& exit, const MenuOption::HandlerType& simple_mode,
    const MenuOption::HandlerType& two_players_mode, std::istream& input_stream)
{
  // Common menu
  auto exit_menu_option = std::make_shared<MenuOption>(k_exit_menu_option_text,exit);
  auto simple_mode_menu_option = std::make_shared<MenuOption>(k_simple_mode_menu_option_text,simple_mode);
  auto two_players_mode_menu_option = std::make_shared<MenuOption>(k_two_players_mode_menu_option_text,two_players_mode);

  auto common_menu = std::make_shared<Menu>();

  common_menu->AddOption(exit_menu_option);
  common_menu->AddOption(simple_mode_menu_option);
  common_menu->AddOption(two_players_mode_menu_option);

  // User input
  auto menu_option_input = std::make_shared<MenuOptionInput>(input_stream,common_menu);

  // Title
  auto title_label = std::make_shared<Label>(k_title_text);

  // Status label
  status_label_ = std::make_shared<Label>("",false);

  // Game table
  game_table_ = std::make_shared<WidgetsContainer>(1,false);

  // Common window
  widgets_.AddWidget(title_label);
  widgets_.AddWidget(common_menu);
  widgets_.AddWidget(status_label_);
  widgets_.AddWidget(game_table_);
  widgets_.AddWidget(menu_option_input);
}

void GameView::SetStatusLabelText(std::string_view text)
{
  status_label_->SetText(text);
  status_label_->SetVisible();
}

void GameView::CleanStatusLabelText()
{
  status_label_->SetText("");
  status_label_->SetInvisible();
}

void GameView::OutputToStream(std::ostream& output_stream)
{
  output_stream << widgets_;
}

void GameView::SetGameTableSimpleMode(const ::playingcards::Hand::ShrPtr& hand)
{
  auto player_title_label = std::make_shared<Label>(k_simple_mode_player_title_text);
  auto player_hand_view = std::make_shared<CardsHandView>(hand);
  auto hand_combination_label = std::make_shared<Label>(k_combination_prefix_text +
      ::playingcards::GetPokerCombinationText(hand->GetPokerCombination()));

  SetStatusLabelText(k_simple_mode_menu_option_text);

  game_table_->Clear();

  game_table_->AddWidget(player_title_label);
  game_table_->AddWidget(player_hand_view);
  game_table_->AddWidget(hand_combination_label);

  game_table_->SetVisible();
}

void GameView::SetGameTableTwoPlayersMode(const ::playingcards::Player& player_1,
    const ::playingcards::Player& player_2)
{
  auto player_1_name_label = std::make_shared<Label>(player_1.name);
  auto player_1_hand_view = std::make_shared<CardsHandView>(player_1.hand);
  auto player_1_combination_label = std::make_shared<Label>(k_combination_prefix_text +
      ::playingcards::GetPokerCombinationText(player_1.hand->GetPokerCombination()));

  auto player_2_name_label = std::make_shared<Label>(player_2.name);
  auto player_2_hand_view = std::make_shared<CardsHandView>(player_2.hand);
  auto player_2_combination_label = std::make_shared<Label>(k_combination_prefix_text +
      ::playingcards::GetPokerCombinationText(player_2.hand->GetPokerCombination()));

  std::string winner_text = k_winner_prefix_text;

  if (*player_1.hand == *player_2.hand) {
    winner_text += k_draw_text;
  }
  else if (*player_1.hand < *player_2.hand) {
    winner_text += player_2.name + "!";
  }
  else {
    winner_text += player_1.name + "!";
  }

  auto winner_label = std::make_shared<Label>(winner_text);

  SetStatusLabelText(k_two_players_mode_menu_option_text);

  game_table_->Clear();

  game_table_->AddWidget(player_1_name_label);
  game_table_->AddWidget(player_1_hand_view);
  game_table_->AddWidget(player_1_combination_label);

  game_table_->AddWidget(player_2_name_label);
  game_table_->AddWidget(player_2_hand_view);
  game_table_->AddWidget(player_2_combination_label);

  game_table_->AddWidget(winner_label);

  game_table_->SetVisible();
}

void GameView::SetExitFrame()
{
  widgets_.Clear();

  widgets_.AddWidget(std::make_shared<Label>(k_exit_message_text));
}

} // namespace playingcards
} // namespace console
} // namespace ui
