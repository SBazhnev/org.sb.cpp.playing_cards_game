// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef UI_CONSOLE_MENU_OPTION_INPUT_H_
#define UI_CONSOLE_MENU_OPTION_INPUT_H_

#include <functional>
#include <iostream>
#include <memory>

#include "ui/console/widget.h"
#include "ui/console/menu.h"

namespace ui {
namespace console {

class MenuOptionInput : public Widget {
public:
  using WeakPtr = std::weak_ptr<MenuOptionInput>;
  using ShrPtr = std::shared_ptr<MenuOptionInput>;
  using UnqPtr = std::unique_ptr<MenuOptionInput>;

  explicit MenuOptionInput(std::istream& input_stream, const Menu::ShrPtr& menu, bool visible = true) :
      Widget{visible},
      input_stream_(&input_stream),
      menu_(menu)
  {
  }

  MenuOptionInput(const MenuOptionInput&) = delete;
  MenuOptionInput& operator=(const MenuOptionInput&) = delete;

  MenuOptionInput(MenuOptionInput&&) = default;
  MenuOptionInput& operator=(MenuOptionInput&&) = default;

  ~MenuOptionInput() = default;

protected:
  void OutputToStream(std::ostream&) override;

private:
  std::istream* input_stream_;
  Menu::ShrPtr menu_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_MENU_OPTION_INPUT_H_
