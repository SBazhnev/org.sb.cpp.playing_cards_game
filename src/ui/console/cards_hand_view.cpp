// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include <ui/console/cards_hand_view.h>

#include <iomanip>
#include <sstream>

#include "playingcards/card.h"

namespace ui {
namespace console {
namespace playingcards {

void CardsHandView::OutputToStream(std::ostream& output_stream)
{
  if (!this->IsHide()) {
    std::stringstream top_bottom_border;
    std::stringstream side_border;
    std::stringstream ranks;
    std::stringstream suits;

    for (const auto& card : hand_->GetCards()) {
      top_bottom_border << "+----------+";
      side_border       << "|          |";
      ranks << "| " << std::left << std::setw(9) << ::playingcards::GetCardRankText(card->rank) << "|";
      suits << "| " << std::left << std::setw(9) << ::playingcards::GetCardSuitText(card->suit)  << "|";
    }

    output_stream << top_bottom_border.rdbuf()  << '\n';
    output_stream << side_border.rdbuf()        << '\n';
    output_stream << side_border.rdbuf()        << '\n';
    output_stream << ranks.rdbuf()              << "\n";
    output_stream << suits.rdbuf()              << "\n";
    output_stream << side_border.rdbuf()        << '\n';
    output_stream << side_border.rdbuf()        << '\n';
    output_stream << top_bottom_border.rdbuf();
  }
}

} // namespace playingcards
} // namespace console
} // namespace ui