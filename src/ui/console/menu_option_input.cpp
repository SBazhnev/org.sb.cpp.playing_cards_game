// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include <ui/console/menu_option_input.h>

#include <limits>
#include <stdexcept>
#include <string>

namespace ui {
namespace console {

const std::string k_promt_text = "Enter menu option number >> ";

void MenuOptionInput::OutputToStream(std::ostream& output_stream)
{
  if (this->IsVisible()) {
    std::size_t menu_option_index = 0;

    output_stream << k_promt_text;
    *input_stream_ >> menu_option_index;

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
