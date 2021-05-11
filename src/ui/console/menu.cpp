// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <ui/console/menu.h>

#include <cassert>
#include <iterator>

namespace ui {
namespace console {

void Menu::ExecuteOptionHandler(int index)
{
  assert((index >= 0 && index <= options_.size()-1) && "Index out of range");

  options_[index].get()->HandlerExecute();
}

void Menu::OutputToStream(std::ostream& output_stream)
{
  if (this->IsVisible()) {
    for (auto option_itr = options_.begin(); option_itr != options_.end(); ++option_itr) {
      output_stream << (option_itr - options_.begin()) << ": " << *option_itr->get();
      if (option_itr != --options_.end()) {
        output_stream << " | ";
      }
    }
  }
}

void Menu::AddOption(const MenuOption::ShrPtr& option)
{
  assert(option && "Option is null");

  options_.emplace_back(option);
}

} // namespace console
} // namespace ui
