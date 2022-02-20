#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include <iterator>
#include <type_traits>

namespace ptxx 
{
	namespace common 
	{
		template<class NumericType>
		auto constexpr factorial(NumericType& num_el) -> std::uint64_t
		{

			if (isPositiveTypename(num_el) && num_el != 0)
			{
				std::uint64_t result = 1;

				for (NumericType i = 0; i <= num_el; ++i)
				{
					result *= result * i;
				}
				return result;
			}
			return 1;
		};

		/*template<class NumericType>
		auto constexpr isPositiveTypename(NumericType& type_name) -> bool
		{
			return
				std::is_same<T, unsigned int>::value   ||
				std::is_same<T, uint8_t>::value        ||
				std::is_same<T, uint16_t>::value       ||
				std::is_same<T, uint32_t>::value       ||
				std::is_same<T, uint64_t>::value       ||
				std::is_same<T, uint_fast8_t>::value   ||
				std::is_same<T, uint_fast16_t>::value  ||
				std::is_same<T, uint_fast32_t>::value  ||
				std::is_same<T, uint_fast64_t>::value  ||
				std::is_same<T, uint_least8_t>::value  ||
				std::is_same<T, uint_least16_t>::value ||
				std::is_same<T, uint_least32_t>::value ||
				std::is_same<T, uint_least64_t>::value;
		};*/

		template<typename T>
		constexpr bool isPositiveTypename =
			std::is_same<T, unsigned int>::value ||
			std::is_same<T, uint8_t>::value ||
			std::is_same<T, uint16_t>::value ||
			std::is_same<T, uint32_t>::value ||
			std::is_same<T, uint64_t>::value ||
			std::is_same<T, uint_fast8_t>::value ||
			std::is_same<T, uint_fast16_t>::value ||
			std::is_same<T, uint_fast32_t>::value ||
			std::is_same<T, uint_fast64_t>::value ||
			std::is_same<T, uint_least8_t>::value ||
			std::is_same<T, uint_least16_t>::value ||
			std::is_same<T, uint_least32_t>::value ||
			std::is_same<T, uint_least64_t>::value;
	}
}

namespace ptxx {
	namespace combinatorics 
	{

		typedef double rf;

		// Based on n! formula

		template<class NumericType>
		decltype(auto) constexpr allPermutations(NumericType &count)
		{
			return common::factorial(count);
		}

		// Based on formula
		// A m,n = n! / (n - m)!
		template <class NumericType>
		decltype(auto) constexpr variations(NumericType places, NumericType elements)
		{
			
			if (elements < places) 
				return static_cast<NumericType>(0);

			NumericType exp = elements - places;

			NumericType numenator = common::factorial(elements);

			NumericType denominator = common::factorial(exp);

			return numenator / denominator;
		}


		// Based on formula
		// C m,n =  n! / ((n-m)! * m!)
		template <class NumericType>
		decltype(auto) constexpr combinations(NumericType places, NumericType elements)
		{
			if (elements < places)
				return static_cast<NumericType>(0);

			NumericType numenator = common::factorial(elements);

			NumericType exp = elements - places;

			NumericType fact_places = common::factorial(places);

			NumericType denominator = common::factorial(exp) * fact_places;

			return numenator / denominator;
		}

		template<class NumericType, class = std::enable_if_t<common::isPositiveTypename<NumericType>>>
		decltype(auto) constexpr relative_frequency(NumericType appeared_events, NumericType common_events)
		{
			//if (!common::isPositiveTypename(appeared_events) || !common::isPositiveTypename(common_events))
			//	throw std::invalid_argument("Relative frequency has invalid argument");

			rf result = static_cast<rf>(appeared_events) / static_cast<rf>(common_events);

			if (result > 1)
				throw std::bad_exception("Relative frequency more than 1");

			return result;
		}
	}
}

#endif // !COMBINATORICS_HPP
