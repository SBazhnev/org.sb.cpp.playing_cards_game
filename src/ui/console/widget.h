// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef UI_CONSOLE_WIDGET_H_
#define UI_CONSOLE_WIDGET_H_

#include <ostream>
#include <memory>

namespace ui {
namespace console {

class Widget {
public:
  using WeakPtr = std::weak_ptr<Widget>;
  using ShrPtr = std::shared_ptr<Widget>;
  using UnqPtr = std::unique_ptr<Widget>;

  Widget(const Widget&) = delete;
  Widget& operator=(const Widget&) = delete;

  Widget(Widget&&) = default;
  Widget& operator=(Widget&&) = default;

  virtual ~Widget() = default;

  friend std::ostream& operator<<(std::ostream& out_stream, Widget& widget)
  {
    widget.OutputToStream(out_stream);
    return out_stream;
  }

  bool IsVisible()
  {
    return visible_;
  }

  void SetVisible()
  {
    visible_ = true;
  }

  void SetInvisible()
  {
    visible_ = false;
  }

protected:
  explicit Widget(bool visible = true) : visible_{visible}
  {
  };

  virtual void OutputToStream(std::ostream&) = 0;

private:
  bool visible_;

};

} /* namespace ui */
} /* namespace console */

#endif // UI_CONSOLE_WIDGET_H_
