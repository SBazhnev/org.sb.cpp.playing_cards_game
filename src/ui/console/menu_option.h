// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
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

class MenuOption : public Widget {
public:
  using WeakPtr = std::weak_ptr<MenuOption>;
  using ShrPtr = std::shared_ptr<MenuOption>;
  using UnqPtr = std::unique_ptr<MenuOption>;

  using HandlerType = std::function<void()>;

  explicit MenuOption(std::string_view title, const MenuOption::HandlerType& handler,
      bool visible = true) : Widget{visible}, title_{title}, handler_(handler)
  {
  }

  ~MenuOption() = default;

  MenuOption(const MenuOption&) = default;
  MenuOption& operator=(const MenuOption&) = default;

  MenuOption(MenuOption&&) = default;
  MenuOption& operator=(MenuOption&&) = default;

  void HandlerExecute();

protected:
  void OutputToStream(std::ostream&) override;

private:
  std::string title_;
  MenuOption::HandlerType handler_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_MENU_OPTION_H_
