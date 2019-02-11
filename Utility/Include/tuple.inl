#pragma once

#include <tuple>

#include "integer-sequence.inl"
#include "for-each.inl"

namespace Utility
{
	namespace Private
	{

		template <typename F, typename Tuple, std::size_t... Is>
		constexpr auto call_with_tuple_elements_impl(F &&f, Tuple &&args, Utility::IntegralSequence<std::size_t, Is...>) -> decltype(f(std::get<Is>(args)...))
		{
			return f(std::get<Is>(args)...);
		}

		template <typename F, typename Tuple>
		constexpr auto call_with_tuple_elements(F &&f, Tuple &&args) ->
			decltype(call_with_tuple_elements_impl(std::forward<F>(f), std::forward<Tuple>(args), Utility::MakeIntegralSequence<std::size_t, std::tuple_size<typename std::remove_reference<Tuple>::type>::value>()))
		{
			return call_with_tuple_elements_impl(std::forward<F>(f), std::forward<Tuple>(args), Utility::MakeIntegralSequence<std::size_t, std::tuple_size<typename std::remove_reference<Tuple>::type>::value>());
		}
	}
	using Private::call_with_tuple_elements;
}