// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef SRC_UI_CONSOLE_GAME_VIEW_H_
#define SRC_UI_CONSOLE_GAME_VIEW_H_

#include <istream>
#include <string_view>

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
  GameView() : widgets_(), status_label_{nullptr}
  {
  }

  ~GameView() = default;

  GameView(const GameView&) = default;
  GameView& operator=(const GameView&) = default;

  GameView(GameView&&) = default;
  GameView& operator=(GameView&&) = default;
  
  void Create(const MenuOptionHandlerType& exit, const MenuOptionHandlerType& simple_mode,
      const MenuOptionHandlerType& two_players_mode, std::istream& input_stream);

  void SetStatusLabelText(std::string_view text);
  void CleanStatusLabelText();

protected:
  void OutputToStream(std::ostream&) override;

private:
  using WeakPtr = std::weak_ptr<Widget>;
  using ShrPtr = std::shared_ptr<Widget>;

  WidgetsContainer widgets_;

  Label::ShrPtr status_label_;

};

} // namespace playingcards
} // namespace console
} // namespace ui

#endif // SRC_UI_CONSOLE_GAME_VIEW_H_
