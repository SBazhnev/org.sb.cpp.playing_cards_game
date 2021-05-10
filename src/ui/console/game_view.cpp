// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "ui/console/game_view.h"

#include <memory>
#include <string>

#include "ui/console/label.h"
#include "ui/console/menu.h"

namespace ui {
namespace console {
namespace playingcards {

const std::string title_text = "The simple playing cards game";

const std::string exit_menu_option_text = "Exit";
const std::string simple_mode_menu_option_text = "Simple mode";
const std::string two_players_mode_menu_option_text = "Two players";

void GameView::OutputToStream(std::ostream& output_stream)
{
  output_stream << widgets_;
}

void GameView::Create(const MenuOptionHandlerType& exit, const MenuOptionHandlerType& simple_mode,
    const MenuOptionHandlerType& two_players_mode, const InputHandler& input,
        std::istream& input_stream)
{
  // Common menu
  auto exit_menu_option = std::make_shared<MenuOption>(exit_menu_option_text,exit);
  auto simple_mode_menu_option = std::make_shared<MenuOption>(simple_mode_menu_option_text,simple_mode);
  auto two_players_mode_menu_option = std::make_shared<MenuOption>(two_players_mode_menu_option_text,two_players_mode);

  auto common_menu = std::make_shared<Menu>();

  common_menu->AddOption(exit_menu_option);
  common_menu->AddOption(simple_mode_menu_option);
  common_menu->AddOption(two_players_mode_menu_option);

  // User input
  auto menu_option_input = std::make_shared<MenuOptionInput>(input_stream,input);

  // Title
  auto title_label = std::make_shared<Label>(title_text);

  // Status label
  auto status_label = std::make_shared<Label>("",true);

  // Game table
  auto game_table = std::make_shared<WidgetsContainer>(1,true);

  // Common window
  widgets_.AddWidget(title_label);
  widgets_.AddWidget(common_menu);
  widgets_.AddWidget(status_label);
  widgets_.AddWidget(game_table);
  widgets_.AddWidget(menu_option_input);
}

} // namespace playingcards
} // namespace console
} // namespace ui
