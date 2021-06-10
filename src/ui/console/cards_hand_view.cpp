// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
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
  if (this->IsVisible()) {
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

    output_stream << top_bottom_border.str()  << '\n';
    output_stream << side_border.str()        << '\n';
    output_stream << side_border.str()        << '\n';
    output_stream << ranks.str()              << "\n";
    output_stream << suits.str()              << "\n";
    output_stream << side_border.str()        << '\n';
    output_stream << side_border.str()        << '\n';
    output_stream << top_bottom_border.str();
  }
}

} // namespace playingcards
} // namespace console
} // namespace ui
