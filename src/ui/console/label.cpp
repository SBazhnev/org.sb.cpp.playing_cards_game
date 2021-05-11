// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <ui/console/label.h>

namespace ui {
namespace console {

void Label::OutputToStream(std::ostream& output_stream)
{
  if (this->IsVisible()) {
    output_stream << text_;
  }
}

void Label::SetText(std::string_view text)
{
  text_ = text;
}

} // namespace console
} // namespace ui
