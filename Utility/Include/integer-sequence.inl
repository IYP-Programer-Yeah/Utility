#pragma once

#include <utility>

namespace Utility
{
	namespace Private
	{
		template <typename T, T... Series>
		struct IntegralSequence {};

		template <typename T>
		constexpr bool is_empty_sequence(T Begin, T End, T Step)
		{
			return (End * Step) <= (Begin * Step);
		}

		template <typename T, T... Head, T... Tail>
		IntegralSequence<T, Head..., Tail...> append_integral_sequence_impl(IntegralSequence<T, Head...>, IntegralSequence<T, Tail...>);

		template <typename Head, typename Tail>
		using AppendIntegralSequence = decltype(append_integral_sequence_impl(std::declval<Head>(), std::declval<Tail>()));

		template <typename T, T Begin, T End, T Step, bool Empty = false>
		struct MakeIntegralSequenceImpl
		{
			using Type = typename std::conditional<Private::is_empty_sequence(Begin, End, Step),
				IntegralSequence<T>,
				AppendIntegralSequence<IntegralSequence<T, Begin>,
				typename MakeIntegralSequenceImpl<T, Begin + Step, End, Step, Private::is_empty_sequence(Begin, End, Step)>::Type>>::type;
		};

		template <typename T, T Begin, T End, T Step>
		struct MakeIntegralSequenceImpl<T, Begin, End, Step, true>
		{
			using Type = IntegralSequence<T>;
		};

		template <typename T, T End, T Begin = 0, T Step = 1>
		using MakeIntegralSequence = typename Private::MakeIntegralSequenceImpl<T, Begin, End, Step>::Type;
	}

	using Private::IntegralSequence;
	using Private::AppendIntegralSequence;
	using Private::MakeIntegralSequence;
}