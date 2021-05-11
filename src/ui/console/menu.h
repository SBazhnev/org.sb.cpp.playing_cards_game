// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef UI_CONSOLE_MENU_H_
#define UI_CONSOLE_MENU_H_

#include <memory>
#include <ostream>
#include <vector>

#include <ui/console/widget.h>
#include <ui/console/menu_option.h>

namespace ui {
namespace console {

class Menu : public Widget {
public:
  using WeakPtr = std::weak_ptr<Menu>;
  using ShrPtr = std::shared_ptr<Menu>;

  explicit Menu(bool hide = false) : Widget{hide}, options_{}
  {
  }

  void ExecuteOptionHandler(int index);

  void AddOption(const MenuOption::ShrPtr& option);

protected:
  void OutputToStream(std::ostream&) override;

private:
  // TODO maybe better to use std::set?
  std::vector<MenuOption::ShrPtr> options_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_MENU_H_
