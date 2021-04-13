// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <ui/console/menu.h>

#include <iterator>

namespace ui {
namespace console {

void Menu::ExecuteOptionHandler(int index)
{
  if (auto option = options_[index].lock()) {
    option->HandlerExecute();
  }
}

void Menu::OutputToStream(std::ostream& output_stream)
{
  if (!this->IsHide()) {
    for (auto option_itr = options_.begin(); option_itr != options_.end(); ++option_itr) {
      if (auto option = option_itr->lock()) {
        output_stream << (option_itr - options_.begin()) << ": " << *option.get();
        if (option_itr != --options_.end()) {
          output_stream << " | ";
        }
      }
    }
  }
}

void Menu::AddOption(MenuOption::WeakPtr&& option)
{
  options_.emplace_back(option);
}

} // namespace console
} // namespace ui
