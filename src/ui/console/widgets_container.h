// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef UI_CONSOLE_WIDGETS_CONTAINER_H_
#define UI_CONSOLE_WIDGETS_CONTAINER_H_

#include <memory>
#include <ostream>
#include <vector>

#include "ui/console/widget.h"

namespace ui {
namespace console {

class WidgetsContainer : public Widget {
public:
  using WeakPtr = std::weak_ptr<WidgetsContainer>;
  using ShrPtr = std::shared_ptr<WidgetsContainer>;

  explicit WidgetsContainer(unsigned int column = 1, bool visible = true) :
        Widget{visible}, widgets_{}, column_{column}
  {
  }

  WidgetsContainer(const WidgetsContainer&) = delete;
  WidgetsContainer& operator=(const WidgetsContainer&) = delete;

  WidgetsContainer(WidgetsContainer&&) = default;
  WidgetsContainer& operator=(WidgetsContainer&&) = default;

  virtual ~WidgetsContainer() = default;

  void AddWidget(const Widget::WeakPtr& widget);

  void Clear();

protected:
  void OutputToStream(std::ostream&) override;

private:
  std::vector<Widget::ShrPtr> widgets_;

  unsigned int column_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_WIDGETS_CONTAINER_H_
