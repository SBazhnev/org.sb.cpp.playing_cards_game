// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef UI_CONSOLE_LABEL_H_
#define UI_CONSOLE_LABEL_H_

#include <memory>
#include <string>
#include <string_view>

#include <ui/console/widget.h>

namespace ui {
namespace console {

class Label : public Widget {
public:
  using WeakPtr = std::weak_ptr<Label>;
  using ShrPtr = std::shared_ptr<Label>;

  explicit Label(std::string_view text, bool hide = false) : Widget{hide}, text_(text)
  {
  }

  void SetText(std::string_view text);

protected:
  void OutputToStream(std::ostream&) override;

private:
  std::string text_;

};

} // namespace console
} // namespace ui

#endif // UI_CONSOLE_LABEL_H_
