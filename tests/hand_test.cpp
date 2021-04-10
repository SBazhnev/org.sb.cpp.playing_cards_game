// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// 
//

#include "playingcards/hand.h"
#include "hand_test.h"

#include <type_traits>

#include <boost/test/unit_test.hpp>

namespace playingcards {
namespace tests {

BOOST_AUTO_TEST_SUITE(HandPokerCombinations)

BOOST_FIXTURE_TEST_CASE_TEMPLATE(RoyalFlush,RF,RoyalFlushes,RF)
{
  BOOST_REQUIRE(RF::hand.GetPokerCombination() == PokerCombination::RoyalFlush);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(StraightFlush,SF,StraightFlushes,SF)
{
  BOOST_REQUIRE(SF::hand.GetPokerCombination() == PokerCombination::StraightFlush);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(FourOfAKind,FK,FourOfAKinds,FK)
{
  BOOST_REQUIRE(FK::hand.GetPokerCombination() == PokerCombination::FourOfAKind);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(FullHouse,FH,FullHouses,FH)
{
  BOOST_REQUIRE(FH::hand.GetPokerCombination() == PokerCombination::FullHouse);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(Flush,Fl,Flushes,Fl)
{
  BOOST_REQUIRE(Fl::hand.GetPokerCombination() == PokerCombination::Flush);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(Straight,St,Straights,St)
{
  BOOST_REQUIRE(St::hand.GetPokerCombination() == PokerCombination::Straight);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(ThreeOfAKind,TK,ThreeOfAKinds,TK)
{
  BOOST_REQUIRE(TK::hand.GetPokerCombination() == PokerCombination::ThreeOfAKind);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(TwoPairs,TP,TwoPairses,TP)
{
  BOOST_REQUIRE(TP::hand.GetPokerCombination() == PokerCombination::TwoPairs);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(OnePair,OP,OnePairs,OP)
{
  BOOST_REQUIRE(OP::hand.GetPokerCombination() == PokerCombination::OnePair);
}

BOOST_FIXTURE_TEST_CASE_TEMPLATE(HighCard,HC,HighCards,HC)
{
  BOOST_REQUIRE(HC::hand.GetPokerCombination() == PokerCombination::HighCard);
}

BOOST_AUTO_TEST_SUITE_END(); // HandPokerCombinations

BOOST_AUTO_TEST_SUITE(HandsCompare)

RoyalFlushClubs royalFlushClubs{};
RoyalFlushDiamonds royalFlushDiamonds{};

StraightFlushNTJQKClubs straightFlushNTJQKClubs{};
StraightFlushNTJQKDiamonds straightFlushNTJQKDiamonds{};
StraightFlushTTFFSDiamonds straightFlushTTFFSDiamonds{};
StraightFlushATTFFDiamonds straightFlushATTFFDiamonds{};

FourOfAKindAAAAKClubs fourOfAKindAAAAKClubs{};
FourOfAKindAAAAKHearts fourOfAKindAAAAKHearts{};
FourOfAKindAAAAQHearts fourOfAKindAAAAQHearts{};
FourOfAKindKKKKAHearts fourOfAKindKKKKAHearts{};

FullHouseAAAKKSpades fullHouseAAAKKSpades{};
FullHouseAAAKKDiamonds fullHouseAAAKKDiamonds{};
FullHouseKKKAADiamonds fullHouseKKKAADiamonds{};

FlushAKQJNClubs flushAKQJNClubs{};
FlushAKQJNSpades flushAKQJNSpades{};
FlushKQJTEHearts flushKQJTEHearts{};

StraightAKQJTSpades straightAKQJTSpades{};
StraightAKQJTHearts straightAKQJTHearts{};
StraightKQJTNClubs straightKQJTNClubs{};
StraightATTFFClubs straightATTFFClubs{};

ThreeOfAKindAAAKQClubs threeOfAKindAAAKQClubs{};
ThreeOfAKindAAAKQSpades threeOfAKindAAAKQSpades{};
ThreeOfAKindAAAQJClubs threeOfAKindAAAQJClubs{};
ThreeOfAKindKKKAQClubs threeOfAKindKKKAQClubs{};

TwoPairsAAKKQClubs twoPairsAAKKQClubs{};
TwoPairsAAKKQSpades twoPairsAAKKQSpades{};
TwoPairsAAQQKSpades twoPairsAAQQKSpades{};
TwoPairsAATTThClubs twoPairsAATTThClubs{};
TwoPairsKKQQJClubs twoPairsKKQQJClubs{};

PairAAKQJClubs pairAAKQJClubs{};
PairAAKQJSpades pairAAKQJSpades{};
PairKKAQJClubs pairKKAQJClubs{};
PairAAQJTClubs pairAAQJTClubs{};

HighCardAKQJNClubs highCardAKQJNClubs{};
HighCardAKQJNSpades highCardAKQJNSpades{};
HighCardKQJTEHearts highCardKQJTEHearts{};

BOOST_AUTO_TEST_CASE(RoyalFlush)
{
  BOOST_REQUIRE(royalFlushClubs.hand == royalFlushDiamonds.hand);

  BOOST_REQUIRE(royalFlushClubs.hand > straightFlushNTJQKClubs.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > fourOfAKindAAAAKClubs.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > fullHouseAAAKKSpades.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > flushAKQJNClubs.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > straightAKQJTSpades.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(royalFlushClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(StraightFlush)
{
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand == straightFlushNTJQKDiamonds.hand);

  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > straightFlushTTFFSDiamonds.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > straightFlushATTFFDiamonds.hand);
  BOOST_REQUIRE(straightFlushTTFFSDiamonds.hand > straightFlushATTFFDiamonds.hand);

  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > fourOfAKindAAAAKClubs.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > fullHouseAAAKKSpades.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > flushAKQJNClubs.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > straightAKQJTSpades.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(straightFlushNTJQKClubs.hand > highCardAKQJNClubs.hand);

  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > fourOfAKindAAAAKClubs.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > fullHouseAAAKKSpades.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > flushAKQJNClubs.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > straightAKQJTSpades.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(straightFlushATTFFDiamonds.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(FourOfAKind)
{
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand == fourOfAKindAAAAKHearts.hand);

  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > fourOfAKindAAAAQHearts.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > fourOfAKindKKKKAHearts.hand);

  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > fullHouseAAAKKSpades.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > flushAKQJNClubs.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > straightAKQJTSpades.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(fourOfAKindAAAAKClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(FullHouse)
{
  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand == fullHouseAAAKKSpades.hand);

  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > fullHouseKKKAADiamonds.hand);

  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > flushAKQJNClubs.hand);
  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > straightAKQJTSpades.hand);
  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(fullHouseAAAKKDiamonds.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(Flush)
{
  BOOST_REQUIRE(flushAKQJNClubs.hand == flushAKQJNSpades.hand);

  BOOST_REQUIRE(flushAKQJNClubs.hand > flushKQJTEHearts.hand);

  BOOST_REQUIRE(flushAKQJNClubs.hand > straightAKQJTSpades.hand);
  BOOST_REQUIRE(flushAKQJNClubs.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(flushAKQJNClubs.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(flushAKQJNClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(flushAKQJNClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(Straight)
{
  BOOST_REQUIRE(straightAKQJTHearts.hand == straightAKQJTSpades.hand);

  BOOST_REQUIRE(straightAKQJTHearts.hand > straightKQJTNClubs.hand);
  BOOST_REQUIRE(straightAKQJTHearts.hand > straightATTFFClubs.hand);
  BOOST_REQUIRE(straightKQJTNClubs.hand > straightATTFFClubs.hand);

  BOOST_REQUIRE(straightAKQJTHearts.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(straightAKQJTHearts.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(straightAKQJTHearts.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(straightAKQJTHearts.hand > highCardAKQJNClubs.hand);

  BOOST_REQUIRE(straightATTFFClubs.hand > threeOfAKindAAAKQClubs.hand);
  BOOST_REQUIRE(straightATTFFClubs.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(straightATTFFClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(straightATTFFClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(ThreeOfAKind)
{
  BOOST_REQUIRE(threeOfAKindAAAKQClubs.hand == threeOfAKindAAAKQSpades.hand);

  BOOST_REQUIRE(threeOfAKindAAAKQClubs.hand > threeOfAKindAAAQJClubs.hand);
  BOOST_REQUIRE(threeOfAKindAAAKQClubs.hand > threeOfAKindKKKAQClubs.hand);

  BOOST_REQUIRE(threeOfAKindAAAKQClubs.hand > twoPairsAAKKQClubs.hand);
  BOOST_REQUIRE(threeOfAKindAAAKQClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(threeOfAKindAAAKQClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(TwoPairs)
{
  BOOST_REQUIRE(twoPairsAAKKQClubs.hand == twoPairsAAKKQSpades.hand);

  BOOST_REQUIRE(twoPairsAAKKQClubs.hand > twoPairsAAQQKSpades.hand);
  BOOST_REQUIRE(twoPairsAATTThClubs.hand > twoPairsKKQQJClubs.hand);

  BOOST_REQUIRE(twoPairsAAKKQClubs.hand > pairAAKQJClubs.hand);
  BOOST_REQUIRE(twoPairsAAKKQClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(OnePair)
{
  BOOST_REQUIRE(pairAAKQJClubs.hand == pairAAKQJSpades.hand);

  BOOST_REQUIRE(pairAAKQJClubs.hand > pairAAQJTClubs.hand);
  BOOST_REQUIRE(pairAAKQJClubs.hand > pairKKAQJClubs.hand);

  BOOST_REQUIRE(pairAAKQJClubs.hand > highCardAKQJNClubs.hand);
}

BOOST_AUTO_TEST_CASE(HighCard)
{
  BOOST_REQUIRE(highCardAKQJNClubs.hand == highCardAKQJNSpades.hand);

  BOOST_REQUIRE(highCardAKQJNClubs.hand > highCardKQJTEHearts.hand);
}

BOOST_AUTO_TEST_SUITE_END(); // HandsCompare

} // namespace tests
} // namespace playingcards
