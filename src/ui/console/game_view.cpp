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

void GameView::Create(const MenuOptionHandlerType& exit, const MenuOptionHandlerType& simple_mode,
    const MenuOptionHandlerType& two_players_mode, std::istream& input_stream)
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
  auto player_name_label = std::make_shared<Label>("Your hand:");
  auto player_hand_view = std::make_shared<CardsHandView>(hand);
  auto hand_combination_title = std::make_shared<Label>("Combination:");
  auto hand_combination_label = std::make_shared<Label>(::playingcards::GetPokerCombinationText(hand->GetPokerCombination()));

  game_table_->Clear();

  game_table_->AddWidget(player_name_label);
  game_table_->AddWidget(player_hand_view);
  game_table_->AddWidget(hand_combination_title);
  game_table_->AddWidget(hand_combination_label);

  game_table_->SetVisible();

  SetStatusLabelText(k_simple_mode_menu_option_text);
}

} // namespace playingcards
} // namespace console
} // namespace ui
