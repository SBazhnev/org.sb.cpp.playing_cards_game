// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <ui/console/menu_option.h>

namespace ui {
namespace console {

void MenuOption::HandlerExecute()
{
  handler_();
}

void MenuOption::OutputToStream(std::ostream& output)
{
  if (!this->IsHide())
    output << title_;
}

} // namespace console
} // namespace ui
