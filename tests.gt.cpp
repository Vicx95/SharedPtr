#include "gtest/gtest.h"
#include "refcounter.hpp"

struct RefCounterTestFixture : public ::testing::Test {
    RefCounter refCounter;
};

TEST_F(RefCounterTestFixture, ifRefCounterIsCreatedCounterShouldAlwaysEqualToZero) {
    //GIVEN
    auto expected = 0;

    //WHEN
    auto result = refCounter.getCounter();

    //THEN
    ASSERT_EQ(result, expected);
}

TEST_F(RefCounterTestFixture, ifPreIncrementOperatorIsUsedCounterShouldAlwaysIncrementByOne) {
    //GIVEN
    auto expected = 2;

    //WHEN
    ++refCounter;
    ++refCounter;
    auto result = refCounter.getCounter();

    //THEN
    ASSERT_EQ(result, expected);
}

TEST_F(RefCounterTestFixture, ifPreIncrementOperatorIsUsedCounterShouldAlwaysDecrementByOne) {
    //GIVEN
    auto expected = 0;

    //WHEN
    ++refCounter;
    ++refCounter;
    --refCounter;
    --refCounter;
    auto result = refCounter.getCounter();

    //THEN
    ASSERT_EQ(result, expected);
}

TEST_F(RefCounterTestFixture, functionResetShouldResetCounterToZero) {
    //GIVEN
    auto expected = 0;

    //WHEN
    ++refCounter;
    ++refCounter;
    ++refCounter;
    ++refCounter;
    refCounter.reset();
    auto result = refCounter.getCounter();

    //THEN
    ASSERT_EQ(result, expected);
}
