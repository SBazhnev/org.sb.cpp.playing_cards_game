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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
  }
};

struct RoyalFlushDiamonds {
  Hand hand;

  RoyalFlushDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Queen));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Nine));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
  }
};

struct StraightFlushNTJQKDiamonds {
  Hand hand;

  StraightFlushNTJQKDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Nine));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Queen));
  }
};

struct StraightFlushTTFFSDiamonds {
  Hand hand;

  StraightFlushTTFFSDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Two));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Four));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Six));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Five));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Three));
  }
};

struct StraightFlushATTFFDiamonds {
  Hand hand;

  StraightFlushATTFFDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Two));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Four));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Five));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Three));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
  }
};

struct FourOfAKindAAAAKHearts {
  Hand hand;

  FourOfAKindAAAAKHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
  }
};

struct FourOfAKindAAAAQHearts {
  Hand hand;

  FourOfAKindAAAAQHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
  }
};

struct FourOfAKindKKKKAHearts {
  Hand hand;

  FourOfAKindKKKKAHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
  }
};

struct FullHouseAAAKKDiamonds {
  Hand hand;

  FullHouseAAAKKDiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
  }
};

struct FullHouseKKKAADiamonds {
  Hand hand;

  FullHouseKKKAADiamonds() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Nine));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
  }
};

struct FlushAKQJNSpades {
  Hand hand;

  FlushAKQJNSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Nine));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Queen));
  }
};

struct FlushKQJTEHearts {
  Hand hand;

  FlushKQJTEHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Eight));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Queen));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Queen));
  }
};

struct StraightAKQJTHearts {
  Hand hand;

  StraightAKQJTHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Queen));
  }
};

struct StraightKQJTNClubs {
  Hand hand;

  StraightKQJTNClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Nine));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Queen));
  }
};

struct StraightATTFFClubs {
  Hand hand;

  StraightATTFFClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Two));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Three));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Four));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Five));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
  }
};

struct ThreeOfAKindAAAKQSpades {
  Hand hand;

  ThreeOfAKindAAAKQSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
  }
};

struct ThreeOfAKindAAAQJClubs {
  Hand hand;

  ThreeOfAKindAAAQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
  }
};

struct ThreeOfAKindKKKAQClubs {
  Hand hand;

  ThreeOfAKindKKKAQClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Queen));
  }
};

struct TwoPairsAAKKQSpades {
  Hand hand;

  TwoPairsAAKKQSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Queen));
  }
};

struct TwoPairsAAQQKSpades {
  Hand hand;

  TwoPairsAAQQKSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
  }
};

struct TwoPairsAAKKJClubs {
  Hand hand;

  TwoPairsAAKKJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Jack));
  }
};

struct TwoPairsAATTThClubs {
  Hand hand;

  TwoPairsAATTThClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Two));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Two));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Three));
  }
};

struct TwoPairsKKQQJClubs {
  Hand hand;

  TwoPairsKKQQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Jack));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
  }
};

struct PairAAKQJSpades {
  Hand hand;

  PairAAKQJSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ace));
  }
};

struct PairKKAQJClubs {
  Hand hand;

  PairKKAQJClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::King));
  }
};

struct PairAAQJTClubs {
  Hand hand;

  PairAAQJTClubs() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Ace));
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
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Diamonds,Card::Rank::Nine));
  }
};

struct HighCardAKQJNSpades {
  Hand hand;

  HighCardAKQJNSpades() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Ace));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Spades,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Nine));
  }
};

struct HighCardKQJTEHearts {
  Hand hand;

  HighCardKQJTEHearts() : hand{}
  {
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Ten));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::King));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Queen));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Hearts,Card::Rank::Jack));
    hand.AddCard(std::make_shared<Card>(Card::Suit::Clubs,Card::Rank::Eight));
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
