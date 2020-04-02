#include <Iyp/Utility/tuple.inl>
#include <gtest/gtest.h>

#include <cstddef>

namespace TupleTest
{
static std::size_t count = 0;

template <std::size_t N>
struct IntegerType
{
};

void PassTupleElementsTestFunction1(IntegerType<0>) { count = 1; }
void PassTupleElementsTestFunction2(IntegerType<0>, IntegerType<1>) { count = 2; }
void PassTupleElementsTestFunction3(IntegerType<0>, IntegerType<1>, IntegerType<2>) { count = 3; }
void PassTupleElementsTestFunction4(IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>) { count = 4; }
void PassTupleElementsTestFunction5(IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>, IntegerType<4>) { count = 5; }

struct MakeFromTupleTestStruct
{
    template <typename... Ts>
    MakeFromTupleTestStruct(Ts &&...) : count(sizeof...(Ts)) {}
    const std::size_t count;
};

TEST(TupleTest, PassTupleElementsTest)
{
    count = 0;
    Iyp::Utility::call_with_tuple_elements(PassTupleElementsTestFunction1, std::tuple<IntegerType<0>>());
    EXPECT_EQ(count, 1);
    count = 0;
    Iyp::Utility::call_with_tuple_elements(PassTupleElementsTestFunction2, std::tuple<IntegerType<0>, IntegerType<1>>());
    EXPECT_EQ(count, 2);
    count = 0;
    Iyp::Utility::call_with_tuple_elements(PassTupleElementsTestFunction3, std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>>());
    EXPECT_EQ(count, 3);
    count = 0;
    Iyp::Utility::call_with_tuple_elements(PassTupleElementsTestFunction4, std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>>());
    EXPECT_EQ(count, 4);
    count = 0;
    Iyp::Utility::call_with_tuple_elements(PassTupleElementsTestFunction5, std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>, IntegerType<4>>());
    EXPECT_EQ(count, 5);
}

TEST(TupleTest, MakeFromTupleTest)
{
    EXPECT_EQ(Iyp::Utility::make_from_tuple<MakeFromTupleTestStruct>(std::tuple<IntegerType<0>>()).count, 1);
    EXPECT_EQ(Iyp::Utility::make_from_tuple<MakeFromTupleTestStruct>(std::tuple<IntegerType<0>, IntegerType<1>>()).count, 2);
    EXPECT_EQ(Iyp::Utility::make_from_tuple<MakeFromTupleTestStruct>(std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>>()).count, 3);
    EXPECT_EQ(Iyp::Utility::make_from_tuple<MakeFromTupleTestStruct>(std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>>()).count, 4);
    EXPECT_EQ(Iyp::Utility::make_from_tuple<MakeFromTupleTestStruct>(std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>, IntegerType<4>>()).count, 5);
}
} // namespace TupleTest
