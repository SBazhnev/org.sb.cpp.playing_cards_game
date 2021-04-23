// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

#include "playingcards/hand.h"

namespace playingcards {

class Player {
public:
  Player(const std::string& name = std::string(), const Hand& hand = Hand()) :
    name_(name), hand_(hand)
  {
  }

  ~Player() = default;

  Player(const Player&) = default;
  Player& operator=(const Player&) = default;

  Player(Player&&) = default;
  Player& operator=(Player&&) = default;

  const Hand& GetHand() const
  {
    return hand_;
  }

  void SetHand(const Hand& hand)
  {
    hand_ = hand;
  }

  const std::string& GetName() const
  {
    return name_;
  }

  void SetName(const std::string& name)
  {
    name_ = name;
  }

private:
  std::string name_;
  Hand hand_;

};

} // namespace playingcards

#endif // PLAYER_H_
