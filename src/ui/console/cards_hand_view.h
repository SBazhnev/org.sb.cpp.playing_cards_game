// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#ifndef UI_CONSOLE_CARDS_HAND_VIEW_H_
#define UI_CONSOLE_CARDS_HAND_VIEW_H_

#include <memory>

#include "playingcards/hand.h"
#include "ui/console/widget.h"

namespace ui {
namespace console {
namespace playingcards {

class CardsHandView : public Widget {
public:
  using WeakPtr = std::weak_ptr<CardsHandView>;
  using ShrPtr = std::shared_ptr<CardsHandView>;
  using UnqPtr = std::unique_ptr<CardsHandView>;

  explicit CardsHandView(const ::playingcards::Hand::ShrPtr& hand = nullptr) : hand_{hand}
  {
  }
  
  ~CardsHandView() = default;

  CardsHandView(const CardsHandView&) = default;
  CardsHandView& operator=(const CardsHandView&) = default;

  CardsHandView(CardsHandView&&) = default;
  CardsHandView& operator=(CardsHandView&&) = default;

protected:
  void OutputToStream(std::ostream&) override;

private:
  ::playingcards::Hand::ShrPtr hand_;

};

} // namespace playingcards
} // namespace console
} // namespace ui

#endif // UI_CONSOLE_CARDS_HAND_VIEW_H_
