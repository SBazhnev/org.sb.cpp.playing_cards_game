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
    unsigned short menu_option_index;

    output_stream << "Enter menu option number >> ";
    *input_stream_ >> menu_option_index;

    // TODO handle valid user input
    if (input_stream_->fail()) {
      input_stream_->clear();
      input_stream_->ignore(std::numeric_limits<std::streamsize>::max(),'\n');

      std::runtime_error("Incorrect input!");
    }

    input_handler_(menu_option_index);
  }
}

} // namespace console
} // namespace ui
