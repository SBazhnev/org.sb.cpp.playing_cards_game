// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include <ui/console/widgets_container.h>

#include <typeindex>

namespace ui {
namespace console {

void WidgetsContainer::AddWidget(const Widget::WeakPtr& widget)
{
  widgets_.emplace_back(widget);
}

void WidgetsContainer::Clear()
{
  widgets_.clear();
}

void WidgetsContainer::OutputToStream(std::ostream& output_stream)
{
  if (this->IsVisible()) {
    unsigned int column_index = 0;

    for (auto& widget : widgets_) {
      if (widget->IsVisible()) {
        output_stream << *widget.get();

        if (std::type_index(typeid(*widget.get())) != std::type_index(typeid(WidgetsContainer))) {
          if (++column_index == column_) {
            output_stream << '\n';
            column_index = 0;
          }
          else {
            output_stream << " ";
          }
        }
      }
    }
  }
}

} // namespace console
} // namespace ui
