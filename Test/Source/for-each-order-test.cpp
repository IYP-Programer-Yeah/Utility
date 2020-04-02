#include <Iyp/Utility/for-each.inl>
#include <gtest/gtest.h>

#include <cstddef>

namespace ForEachOrderTest
{
static std::size_t count = 0;

void OrderTestFunction(std::size_t n)
{
    if (n == count)
        count++;
}

TEST(ForEachOrderTest, Simple)
{
    Iyp::Utility::for_each(OrderTestFunction, 0, 1, 2, 3, 4);
    EXPECT_EQ(count, 5);
}
} // namespace ForEachOrderTest
