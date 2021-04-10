// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#ifndef HAND_TEST_H_
#define HAND_TEST_H_

#include <boost/mpl/vector.hpp>

#include "playingcards/hand.h"

namespace playingcards {
namespace tests {

//////// RoyalFlush ////////

struct RoyalFlushClubs {
  Hand hand;

  RoyalFlushClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
  }
};

struct RoyalFlushDiamonds {
  Hand hand;

  RoyalFlushDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Queen));
  }
};

using RoyalFlushes = boost::mpl::vector<
    RoyalFlushClubs,
    RoyalFlushDiamonds
>;

//////// RoyalFlush end ////////

//////// StraightFlush ////////

struct StraightFlushNTJQKClubs {
  Hand hand;

  StraightFlushNTJQKClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Nine));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
  }
};

struct StraightFlushNTJQKDiamonds {
  Hand hand;

  StraightFlushNTJQKDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Nine));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Queen));
  }
};

struct StraightFlushTTFFSDiamonds {
  Hand hand;

  StraightFlushTTFFSDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Two));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Four));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Six));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Five));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Three));
  }
};

struct StraightFlushATTFFDiamonds {
  Hand hand;

  StraightFlushATTFFDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Two));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Four));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Five));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Three));
  }
};

using StraightFlushes = boost::mpl::vector<
    StraightFlushNTJQKClubs,
    StraightFlushNTJQKDiamonds,
    StraightFlushTTFFSDiamonds,
    StraightFlushATTFFDiamonds
>;

//////// StraightFlush end ////////

//////// FourOfAKind ////////

struct FourOfAKindAAAAKClubs {
  Hand hand;

  FourOfAKindAAAAKClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
  }
};

struct FourOfAKindAAAAKHearts {
  Hand hand;

  FourOfAKindAAAAKHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
  }
};

struct FourOfAKindAAAAQHearts {
  Hand hand;

  FourOfAKindAAAAQHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
  }
};

struct FourOfAKindKKKKAHearts {
  Hand hand;

  FourOfAKindKKKKAHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
  }
};

using FourOfAKinds = boost::mpl::vector<
    FourOfAKindAAAAKClubs,
    FourOfAKindAAAAKHearts,
    FourOfAKindAAAAQHearts,
    FourOfAKindKKKKAHearts
>;

//////// FourofAKind end ////////

//////// FullHouse ////////

struct FullHouseAAAKKSpades {
  Hand hand;

  FullHouseAAAKKSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
  }
};

struct FullHouseAAAKKDiamonds {
  Hand hand;

  FullHouseAAAKKDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
  }
};

struct FullHouseKKKAADiamonds {
  Hand hand;

  FullHouseKKKAADiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
  }
};

using FullHouses = boost::mpl::vector<
    FullHouseAAAKKSpades,
    FullHouseAAAKKDiamonds,
    FullHouseKKKAADiamonds
>;

//////// FullHouse end ////////

//////// Flush ////////

struct FlushAKQJNClubs {
  Hand hand;

  FlushAKQJNClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Nine));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
  }
};

struct FlushAKQJNSpades {
  Hand hand;

  FlushAKQJNSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Nine));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Queen));
  }
};

struct FlushKQJTEHearts {
  Hand hand;

  FlushKQJTEHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Eight));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Queen));
  }
};

using Flushes = boost::mpl::vector<
    FlushAKQJNClubs,
    FlushAKQJNSpades,
    FlushKQJTEHearts
>;

//////// Flush end ////////

//////// Straight ////////

struct StraightAKQJTSpades {
  Hand hand;

  StraightAKQJTSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Queen));
  }
};

struct StraightAKQJTHearts {
  Hand hand;

  StraightAKQJTHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Queen));
  }
};

struct StraightKQJTNClubs {
  Hand hand;

  StraightKQJTNClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Nine));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Queen));
  }
};

struct StraightATTFFClubs {
  Hand hand;

  StraightATTFFClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Two));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Three));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Four));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Five));
  }
};

using Straights = boost::mpl::vector<
    StraightAKQJTSpades,
    StraightAKQJTHearts,
    StraightKQJTNClubs,
    StraightATTFFClubs
>;

//////// Straight end ////////

//////// ThreeOfAKind ////////

struct ThreeOfAKindAAAKQClubs {
  Hand hand;

  ThreeOfAKindAAAKQClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
  }
};

struct ThreeOfAKindAAAKQSpades {
  Hand hand;

  ThreeOfAKindAAAKQSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
  }
};

struct ThreeOfAKindAAAQJClubs {
  Hand hand;

  ThreeOfAKindAAAQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
  }
};

struct ThreeOfAKindKKKAQClubs {
  Hand hand;

  ThreeOfAKindKKKAQClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
  }
};

using ThreeOfAKinds = boost::mpl::vector<
    ThreeOfAKindAAAKQClubs,
    ThreeOfAKindAAAKQSpades,
    ThreeOfAKindAAAQJClubs,
    ThreeOfAKindKKKAQClubs
>;

//////// ThreeOfAKind end ////////

//////// TwoPairs ////////

struct TwoPairsAAKKQClubs {
  Hand hand;

  TwoPairsAAKKQClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Queen));
  }
};

struct TwoPairsAAKKQSpades {
  Hand hand;

  TwoPairsAAKKQSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Queen));
  }
};

struct TwoPairsAAQQKSpades {
  Hand hand;

  TwoPairsAAQQKSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
  }
};

struct TwoPairsAAKKJClubs {
  Hand hand;

  TwoPairsAAKKJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Jack));
  }
};

struct TwoPairsAATTThClubs {
  Hand hand;

  TwoPairsAATTThClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Two));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Two));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Three));
  }
};

struct TwoPairsKKQQJClubs {
  Hand hand;

  TwoPairsKKQQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Jack));
  }
};

using TwoPairses = boost::mpl::vector<
    TwoPairsAAKKQClubs,
    TwoPairsAAKKQSpades,
    TwoPairsAAQQKSpades,
    TwoPairsAATTThClubs,
    TwoPairsKKQQJClubs
>;

//////// TwoPairs end ////////

//////// Pair ////////

struct PairAAKQJClubs {
  Hand hand;

  PairAAKQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
  }
};

struct PairAAKQJSpades {
  Hand hand;

  PairAAKQJSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ace));
  }
};

struct PairKKAQJClubs {
  Hand hand;

  PairKKAQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::King));
  }
};

struct PairAAQJTClubs {
  Hand hand;

  PairAAQJTClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Ace));
  }
};

using OnePairs = boost::mpl::vector<
    PairAAKQJClubs,
    PairAAKQJSpades,
    PairKKAQJClubs,
    PairAAQJTClubs
>;

//////// Pair end ////////

//////// High card ////////

struct HighCardAKQJNClubs {
  Hand hand;

  HighCardAKQJNClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Diamonds,CardRank::Nine));
  }
};

struct HighCardAKQJNSpades {
  Hand hand;

  HighCardAKQJNSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Ace));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Spades,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Nine));
  }
};

struct HighCardKQJTEHearts {
  Hand hand;

  HighCardKQJTEHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Ten));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::King));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Queen));
    hand.AddCard(std::make_shared<Card>(CardSuit::Hearts,CardRank::Jack));
    hand.AddCard(std::make_shared<Card>(CardSuit::Clubs,CardRank::Eight));
  }
};

using HighCards = boost::mpl::vector<
    HighCardAKQJNClubs,
    HighCardAKQJNSpades,
    HighCardKQJTEHearts
>;

//////// High card end ////////

} // namespace tests
} // namespace playingcards

#endif // HAND_TEST_H_
