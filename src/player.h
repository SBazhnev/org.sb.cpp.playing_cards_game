// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <string_view>

#include "playingcards/hand.h"

namespace playingcards {

class Player {
public:
  explicit Player(std::string_view name = std::string(), const Hand::ShrPtr& hand = nullptr) :
    name_(name), hand_(hand)
  {
  }

  ~Player() = default;

  Player(const Player&) = default;
  Player& operator=(const Player&) = default;

  Player(Player&&) = default;
  Player& operator=(Player&&) = default;

  const Hand::ShrPtr& GetHand() const
  {
    return hand_;
  }

  void SetHand(const Hand::ShrPtr& hand)
  {
    hand_ = hand;
  }

  const std::string& GetName() const
  {
    return name_;
  }

  void SetName(std::string_view name)
  {
    name_ = name;
  }

private:
  std::string name_;
  Hand::ShrPtr hand_;

};

} // namespace playingcards

#endif // PLAYER_H_
