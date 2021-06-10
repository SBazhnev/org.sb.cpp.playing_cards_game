// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef SRC_UI_CONSOLE_GAME_VIEW_H_
#define SRC_UI_CONSOLE_GAME_VIEW_H_

#include <istream>
#include <memory>
#include <string_view>

#include "player.h"
#include "playingcards/hand.h"

#include "ui/console/label.h"
#include "ui/console/menu_option.h"
#include "ui/console/menu_option_input.h"
#include "ui/console/widget.h"
#include "ui/console/widgets_container.h"

namespace ui {
namespace console {
namespace playingcards {

class GameView : public Widget {
public:
  using WeakPtr = std::weak_ptr<GameView>;
  using ShrPtr = std::shared_ptr<GameView>;
  using UnqPtr = std::unique_ptr<GameView>;

  GameView() : widgets_(), game_table_{nullptr}, status_label_{nullptr}
  {
  }

  ~GameView() = default;

  GameView(const GameView&) = default;
  GameView& operator=(const GameView&) = default;

  GameView(GameView&&) = default;
  GameView& operator=(GameView&&) = default;
  
  void BuildMainFrame(const MenuOption::HandlerType& exit, const MenuOption::HandlerType& simple_mode,
      const MenuOption::HandlerType& two_players_mode, std::istream& input_stream);

  void SetStatusLabelText(std::string_view text);
  void CleanStatusLabelText();

  void SetGameTableSimpleMode(const ::playingcards::Hand::ShrPtr& hand);
  void SetGameTableTwoPlayersMode(const ::playingcards::Player& player_1,
      const ::playingcards::Player& player_2);

  void SetExitFrame();

protected:
  void OutputToStream(std::ostream&) override;

private:
  WidgetsContainer widgets_;

  WidgetsContainer::ShrPtr game_table_;

  Label::ShrPtr status_label_;

};

} // namespace playingcards
} // namespace console
} // namespace ui

#endif // SRC_UI_CONSOLE_GAME_VIEW_H_
