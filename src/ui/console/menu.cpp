// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include <ui/console/menu.h>

#include <cassert>
#include <stdexcept>
#include <iterator>

namespace ui {
namespace console {

void Menu::ExecuteOptionHandler(std::size_t index)
{
  if (index > options_.size()-1)
    throw std::out_of_range("Index out of range");

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
