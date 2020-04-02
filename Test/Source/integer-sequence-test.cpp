#include <Utility/integer-sequence.inl>
#include <gtest/gtest.h>

#include <cstddef>
#include <vector>
#include <cinttypes>

template <typename T, T... Is>
std::vector<T> fill_vector(Utility::IntegerSequence<T, Is...>)
{
    return std::vector<T>{Is...};
}

TEST(IntegerSequenceTest, StepSizesOfOne)
{
    constexpr std::size_t Step = 1;
    constexpr std::size_t Begin = 0;
    constexpr std::size_t End = 100;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::size_t, End, Begin, Step>());

    EXPECT_EQ(result[0], Begin);
    EXPECT_LE((End - result.back()) * Step, Step * Step);
    auto expected_val = Begin;
    for (auto current_val : result)
    {
        EXPECT_EQ(expected_val, current_val);
        expected_val += Step;
    }
}

TEST(IntegerSequenceTest, StepSizesOfN)
{
    constexpr std::size_t Step = 3;
    constexpr std::size_t Begin = 0;
    constexpr std::size_t End = 100;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::size_t, End, Begin, Step>());

    EXPECT_EQ(result[0], Begin);
    EXPECT_LE((End - result.back()) * Step, Step * Step);
    auto expected_val = Begin;
    for (auto current_val : result)
    {
        EXPECT_EQ(expected_val, current_val);
        expected_val += Step;
    }
}

TEST(IntegerSequenceTest, NegetiveStep)
{
    constexpr std::int64_t Step = -1;
    constexpr std::int64_t Begin = 100;
    constexpr std::int64_t End = 0;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result[0], Begin);
    EXPECT_LE((End - result.back()) * Step, Step * Step);
    auto expected_val = Begin;
    for (auto current_val : result)
    {
        EXPECT_EQ(expected_val, current_val);
        expected_val += Step;
    }
}

TEST(IntegerSequenceTest, NegetiveStepAndEnd)
{
    constexpr std::int64_t Step = -3;
    constexpr std::int64_t Begin = 100;
    constexpr std::int64_t End = -10;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result[0], Begin);
    EXPECT_LE((End - result.back()) * Step, Step * Step);
    auto expected_val = Begin;
    for (auto current_val : result)
    {
        EXPECT_EQ(expected_val, current_val);
        expected_val += Step;
    }
}

TEST(IntegerSequenceTest, NegetiveStepBeginAndEnd)
{
    constexpr std::int64_t Step = -3;
    constexpr std::int64_t Begin = -10;
    constexpr std::int64_t End = -100;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result[0], Begin);
    EXPECT_LE((End - result.back()) * Step, Step * Step);
    auto expected_val = Begin;
    for (auto current_val : result)
    {
        EXPECT_EQ(expected_val, current_val);
        expected_val += Step;
    }
}

TEST(IntegerSequenceTest, EmptyNegetiveStepBeginAndEnd)
{
    constexpr std::int64_t Step = -3;
    constexpr std::int64_t Begin = -100;
    constexpr std::int64_t End = -10;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result.size(), 0);
}

TEST(IntegerSequenceTest, EmptyNegetiveBeginAndEnd)
{
    constexpr std::int64_t Step = 3;
    constexpr std::int64_t Begin = -10;
    constexpr std::int64_t End = -100;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result.size(), 0);
}

TEST(IntegerSequenceTest, EmptyNegetiveEnd)
{
    constexpr std::int64_t Step = 3;
    constexpr std::int64_t Begin = 10;
    constexpr std::int64_t End = -100;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result.size(), 0);
}

TEST(IntegerSequenceTest, Empty)
{
    constexpr std::int64_t Step = 3;
    constexpr std::int64_t Begin = 100;
    constexpr std::int64_t End = 10;

    auto result = fill_vector(Utility::MakeIntegerSequence<std::int64_t, End, Begin, Step>());

    EXPECT_EQ(result.size(), 0);
}