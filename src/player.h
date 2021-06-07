// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <string_view>

#include "playingcards/hand.h"

namespace playingcards {

struct Player {
  std::string name;
  Hand::ShrPtr hand;

  explicit Player(std::string_view name_ = std::string(), const Hand::ShrPtr& hand_ = nullptr) :
    name{name_}, hand{hand_}
  {
  }

  ~Player() = default;

  Player(const Player&) = default;
  Player& operator=(const Player&) = default;

  Player(Player&&) = default;
  Player& operator=(Player&&) = default;

};

} // namespace playingcards

#endif // PLAYER_H_
