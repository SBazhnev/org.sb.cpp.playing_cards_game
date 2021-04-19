// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef UI_CONSOLE_MENU_OPTION_INPUT_H_
#define UI_CONSOLE_MENU_OPTION_INPUT_H_

#include <functional>
#include <iostream>
#include <memory>

#include "ui/console/widget.h"

namespace ui {
namespace console {

using InputHandler = std::function<void(unsigned short)>;

class MenuOptionInput : public Widget {
public:
  using WeakPtr = std::weak_ptr<MenuOptionInput>;
  using ShrPtr = std::shared_ptr<MenuOptionInput>;

  explicit MenuOptionInput(std::istream& input_stream, const InputHandler& input_handler,
      bool hide = false) : Widget{hide}, input_stream_(&input_stream),
          input_handler_(input_handler)
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
  InputHandler input_handler_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_MENU_OPTION_INPUT_H_
