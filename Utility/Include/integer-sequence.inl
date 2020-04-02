#pragma once

#include <utility>

namespace Iyp
{
namespace Utility
{
namespace Private
{
template <typename T, T... Series>
struct IntegerSequence
{
};

template <typename T>
constexpr bool is_empty_sequence(T Begin, T End, T Step)
{
    return (End * Step) <= (Begin * Step);
}

template <typename T>
constexpr bool is_a_single_membered_sequence(T Begin, T End, T Step)
{
    return (!is_empty_sequence(Begin, End, Step)) && is_empty_sequence(Begin + Step, End, Step);
}

template <typename T>
constexpr T get_sequence_middle_point(T Begin, T End, T Step)
{
    return ((End - Begin) / Step + 1) / 2 * Step + Begin;
}

template <typename T, T... Head, T... Tail>
IntegerSequence<T, Head..., Tail...> append_integer_sequence_impl(IntegerSequence<T, Head...>, IntegerSequence<T, Tail...>);

template <typename Head, typename Tail>
using AppendIntegerSequence = decltype(append_integer_sequence_impl(std::declval<Head>(), std::declval<Tail>()));

template <typename T, T Begin, T End, T Step, bool Empty = is_empty_sequence(Begin, End, Step), bool Single = is_a_single_membered_sequence(Begin, End, Step)>
struct MakeIntegerSequenceImpl;

template <typename T, T Begin, T End, T Step>
struct MakeIntegerSequenceImpl<T, Begin, End, Step, false, false>
{
    using Type = AppendIntegerSequence<typename MakeIntegerSequenceImpl<T, Begin, get_sequence_middle_point(Begin, End, Step), Step>::Type,
                                       typename MakeIntegerSequenceImpl<T, get_sequence_middle_point(Begin, End, Step), End, Step>::Type>;
};

template <typename T, T Begin, T End, T Step>
struct MakeIntegerSequenceImpl<T, Begin, End, Step, true, false>
{
    using Type = IntegerSequence<T>;
};

template <typename T, T Begin, T End, T Step>
struct MakeIntegerSequenceImpl<T, Begin, End, Step, false, true>
{
    using Type = IntegerSequence<T, Begin>;
};

template <typename T, T End, T Begin = 0, T Step = 1>
using MakeIntegerSequence = typename MakeIntegerSequenceImpl<T, Begin, End, Step>::Type;
} // namespace Private

using Private::AppendIntegerSequence;
using Private::IntegerSequence;
using Private::MakeIntegerSequence;
} // namespace Utility
} // namespace Iyp
