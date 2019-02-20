#include <Utility/tuple.inl>
#include <gtest/gtest.h>

#include <cstddef>

static std::size_t count = 0;

template <std::size_t N>
struct IntegerType {};

void PassAsTupleTestFunction1(IntegerType<0>) { count = 1; }
void PassAsTupleTestFunction2(IntegerType<0>, IntegerType<1>) { count = 2; }
void PassAsTupleTestFunction3(IntegerType<0>, IntegerType<1>, IntegerType<2>) { count = 3; }
void PassAsTupleTestFunction4(IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>) { count = 4; }
void PassAsTupleTestFunction5(IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>, IntegerType<4>) { count = 5; }

TEST(PassAsTupleTestFunction, Simple)
{
	count = 0;
	Utility::call_with_tuple_elements(PassAsTupleTestFunction1, std::tuple<IntegerType<0>>());
	EXPECT_EQ(count, 1);
	count = 0;
	Utility::call_with_tuple_elements(PassAsTupleTestFunction2, std::tuple<IntegerType<0>, IntegerType<1>>());
	EXPECT_EQ(count, 2);
	count = 0;
	Utility::call_with_tuple_elements(PassAsTupleTestFunction3, std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>>());
	EXPECT_EQ(count, 3);
	count = 0;
	Utility::call_with_tuple_elements(PassAsTupleTestFunction4, std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>>());
	EXPECT_EQ(count, 4);
	count = 0;
	Utility::call_with_tuple_elements(PassAsTupleTestFunction5, std::tuple<IntegerType<0>, IntegerType<1>, IntegerType<2>, IntegerType<3>, IntegerType<4>>());
	EXPECT_EQ(count, 5);
}