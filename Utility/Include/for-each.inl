#pragma once

#include <utility>

#include "Iyp/Utility/constexpr.inl"

namespace Iyp
{
namespace Utility
{
namespace Private
{
struct NoOpCtor
{
    template <typename... Args>
    constexpr NoOpCtor(Args &&... args) {}
};

template <typename F, typename... Args>
CPP_14_CONSTEXPR void for_each(F &&f, Args &&... args)
{
    NoOpCtor{(f(std::forward<Args>(args)), true)...};
}
} // namespace Private

using Private::for_each;
} // namespace Utility
} // namespace Iyp
