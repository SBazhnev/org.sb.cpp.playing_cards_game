// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <ui/console/menu_option_input.h>

#include <limits>
#include <stdexcept>

namespace ui {
namespace console {

void MenuOptionInput::OutputToStream(std::ostream& output_stream)
{
  if (this->IsVisible()) {
    std::size_t menu_option_index = 0;

    output_stream << "Enter menu option number >> ";
    *input_stream_ >> menu_option_index;

    std::cout << "menu_option_index = " << menu_option_index << "\n";

    if (input_stream_->fail()) {
      input_stream_->clear();
      input_stream_->ignore(std::numeric_limits<std::streamsize>::max(),'\n');

      throw std::invalid_argument("Incorrect input!");
    }

    menu_->ExecuteOptionHandler(menu_option_index);
  }
}

} // namespace console
} // namespace ui
