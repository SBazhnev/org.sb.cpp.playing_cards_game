// Copyright (c) 2021 Sergey Bazhnev <SBazhnev@gmail.com>
// Licensed under the MIT License
//

#include "playingcards/poker_combinations.h"

#include <boost/test/unit_test.hpp>

namespace playingcards {
namespace tests {

BOOST_AUTO_TEST_SUITE(PokerCombinationText)

BOOST_AUTO_TEST_CASE(HighCard)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::HighCard),"high card");
}

BOOST_AUTO_TEST_CASE(OnePair)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::OnePair),"one pair");
}

BOOST_AUTO_TEST_CASE(TwoPairs)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::TwoPairs),"two pairs");
}

BOOST_AUTO_TEST_CASE(ThreeOfAKind)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::ThreeOfAKind),"three of a kind");
}

BOOST_AUTO_TEST_CASE(Straight)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::Straight),"straight");
}

BOOST_AUTO_TEST_CASE(Flush)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::Flush),"flush");
}

BOOST_AUTO_TEST_CASE(FullHouse)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::FullHouse),"full house");
}

BOOST_AUTO_TEST_CASE(FourOfAKind)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::FourOfAKind),"four of a kind");
}

BOOST_AUTO_TEST_CASE(StraightFlush)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::StraightFlush),"straight flush");
}

BOOST_AUTO_TEST_CASE(RoyalFlush)
{
  BOOST_REQUIRE_EQUAL(GetPokerCombinationText(PokerCombination::RoyalFlush),"royal flush");
}

BOOST_AUTO_TEST_SUITE_END(); // PokerCombinationText

} // namespace tests
} // namespace playingcards
