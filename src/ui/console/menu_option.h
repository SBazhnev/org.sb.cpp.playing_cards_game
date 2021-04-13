// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//
//

#ifndef UI_CONSOLE_MENU_OPTION_H_
#define UI_CONSOLE_MENU_OPTION_H_

#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <string_view>

#include "ui/console/widget.h"

namespace ui {
namespace console {

using MenuOptionHandlerType = std::function<void()>;

class MenuOption : public Widget {
public:
  using WeakPtr = std::weak_ptr<MenuOption>;
  using ShrPtr = std::shared_ptr<MenuOption>;

  explicit MenuOption(std::string_view title, const MenuOptionHandlerType& handler,
      bool hide = false) : Widget{hide}, title_{title}, handler_(handler)
  {
  }

  void HandlerExecute();

protected:
  void OutputToStream(std::ostream&) override;

private:
  std::string title_;
  MenuOptionHandlerType handler_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_MENU_OPTION_H_
