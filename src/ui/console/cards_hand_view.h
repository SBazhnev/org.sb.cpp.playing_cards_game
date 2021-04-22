// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef UI_CONSOLE_CARDS_HAND_VIEW_H_
#define UI_CONSOLE_CARDS_HAND_VIEW_H_

#include "playingcards/hand.h"
#include "ui/console/widget.h"

namespace ui {
namespace console {
namespace playingcards {

class CardsHandView : public Widget {
public:
  explicit CardsHandView(const ::playingcards::Hand::ShrPtr& hand = nullptr) : hand_{hand}
  {
  }
  
protected:
  void OutputToStream(std::ostream&) override;

private:
  ::playingcards::Hand::ShrPtr hand_;

};

} // namespace playingcards
} // namespace console
} // namespace ui

#endif // UI_CONSOLE_CARDS_HAND_VIEW_H_
