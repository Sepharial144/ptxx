#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include <iterator>
#include <typeinfo>

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

		template<class NumericType>
		auto constexpr isPositiveTypename(NumericType& type_name) -> bool
		{

			if (std::is_same<type_name, unsigned int>)
				return true;
			if (std::is_same<type_name, uint8_t>)
				return true;
			if (std::is_same<type_name, uint16_t>)
				return true;
			if (std::is_same<type_name, uint32_t>)
				return true;
			if (std::is_same<type_name, uint64_t>)
				return true;
			if (std::is_same<type_name, uint_fast8_t>)
				return true;
			if (std::is_same<type_name, uint_fast16_t>)
				return true;
			if (std::is_same<type_name, uint_fast32_t>)
				return true;
			if (std::is_same<type_name, uint_fast64_t>)
				return true;
			if (std::is_same<type_name, uint_least8_t>)
				return true;
			if (std::is_same<type_name, uint_least16_t>)
				return true;
			if (std::is_same<type_name, uint_least32_t>)
				return true;
			if (std::is_same<type_name, uint_least64_t>)
				return true;

			return false;
		};
	}
}

namespace ptxx {
	namespace combinatorics 
	{

		struct Al_description
		{
			int time;
			int counts;
		};
			
		typedef double rf;

		template<class NumericType>
		auto constexpr allPermutations(NumericType &count)
		{
			return common::factorial(count);
		}

		template <class NumericType>
		auto constexpr variations(NumericType places, NumericType elements) -> NumericType
		{
			
			if (elements < places) 
				return static_cast<NumericType>(0);

			T exp = elements - places;

			T numenator = common::factorial(elements);

			T denominator = common::factorial(exp);

			return numenator / denominator;
		}

		template <typename NumericType>
		NumericType combinations(NumericType places, NumericType elements)
		{
			if (elements < places)
				return static_cast<NumericType>(0);

			NumericType numenator = common::factorial(elements);

			NumericType exp = elements - places;

			NumericType pls_factorial = common::factorial(places);

			NumericType denominator = common::factorial(exp) * pls_factorial;

			return numenator / denominator;
		}

		template<typename NumericType>
		rf relative_frequency(NumericType appeared_events, NumericType common_events)
		{
			if (!isPositiveTypename(appeared_events) || !isPositiveTypename(common_events))
				throw std::invalid_argument("Relative frequency has invalid argument");

			return static_cast<rf>(appeared_events) / static_cast<rf>(common_events);
		}

		
	}
}

#endif // !COMBINATORICS_HPP
