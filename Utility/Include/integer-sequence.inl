#pragma once

#include <utility>

namespace Utility
{
	namespace Private
	{
		template <typename T, T... Series>
		struct IntegerSequence {};

		template <typename T>
		constexpr bool is_empty_sequence(T Begin, T End, T Step)
		{
			return (End * Step) <= (Begin * Step);
		}

		template <typename T, T... Head, T... Tail>
		IntegerSequence<T, Head..., Tail...> append_integer_sequence_impl(IntegerSequence<T, Head...>, IntegerSequence<T, Tail...>);

		template <typename Head, typename Tail>
		using AppendIntegerSequence = decltype(append_integer_sequence_impl(std::declval<Head>(), std::declval<Tail>()));

		template <typename T, T Begin, T End, T Step, bool Empty = false>
		struct MakeIntegerSequenceImpl
		{
			using Type = typename std::conditional<Private::is_empty_sequence(Begin, End, Step),
				IntegerSequence<T>,
				AppendIntegerSequence<IntegerSequence<T, Begin>,
					typename MakeIntegerSequenceImpl<T, Begin + Step, End, Step, Private::is_empty_sequence(Begin, End, Step)>::Type>>::type;
		};

		template <typename T, T Begin, T End, T Step>
		struct MakeIntegerSequenceImpl<T, Begin, End, Step, true>
		{
			using Type = IntegerSequence<T>;
		};

		template <typename T, T End, T Begin = 0, T Step = 1>
		using MakeIntegerSequence = typename Private::MakeIntegerSequenceImpl<T, Begin, End, Step>::Type;
	}

	using Private::IntegerSequence;
	using Private::AppendIntegerSequence;
	using Private::MakeIntegerSequence;
}