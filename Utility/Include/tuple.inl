#pragma once

#include <tuple>

#include "integer-sequence.inl"
#include "for-each.inl"

namespace Utility
{
	namespace Private
	{

		template <typename F, typename Tuple, std::size_t... Is>
		constexpr auto call_with_tuple_elements_impl(F &&f, Tuple &&args, Utility::IntegerSequence<std::size_t, Is...>) -> decltype(f(std::get<Is>(args)...))
		{
			return f(std::get<Is>(std::forward<Tuple>(args))...);
		}

		template <typename F, typename Tuple>
		constexpr auto call_with_tuple_elements(F &&f, Tuple &&args) ->
			decltype(call_with_tuple_elements_impl(std::forward<F>(f), std::forward<Tuple>(args), Utility::MakeIntegerSequence<std::size_t, std::tuple_size<typename std::remove_reference<Tuple>::type>::value>()))
		{
			return call_with_tuple_elements_impl(std::forward<F>(f), std::forward<Tuple>(args), Utility::MakeIntegerSequence<std::size_t, std::tuple_size<typename std::remove_reference<Tuple>::type>::value>());
		}

		template <class T, class Tuple, std::size_t... Is>
		constexpr T make_from_tuple_impl(Tuple&& args, Utility::IntegerSequence<std::size_t, Is...>)
		{
			return T(std::get<Is>(std::forward<Tuple>(args))...);
		}

		template <class T, class Tuple>
		constexpr T make_from_tuple(Tuple&& args)
		{
			return make_from_tuple_impl<T>(std::forward<Tuple>(args),
				Utility::MakeIntegerSequence<std::size_t, std::tuple_size<typename std::remove_reference<Tuple>::type>::value>());
		}
	}
	using Private::call_with_tuple_elements;
	using Private::make_from_tuple;
}