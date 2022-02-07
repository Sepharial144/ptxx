#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include <iterator>
#include <typeinfo>

namespace pt 
{
	namespace common 
	{
		template<class NumericType>
		auto constexpr factorial(NumericType& num_el) -> std::uint64_t
		{

			if (true == isPositiveTypename(num_el) && num_el != 0)
			{
				std::uint64_t result = 1;

				for (NumericType i = 0; i <= num_el; ++i)
				{
					result = result * i;
				}
				return result;
			}
			return 1;
		}

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
		}

	}
}

namespace pt {
	namespace combinatorics 
	{

		struct Al_description
		{
			int time;
			int counts;
		};
			
		typedef double rf;


		unsigned int getAllPermutations(unsigned int &element)
		{
			return common::factorial(element);
		}

		template <typename T>
		T variations(T places, T elements)
		{
			
			if (elements < places) 
				return static+_cast<T>(0);

			T exp = elements - places;

			T numenator = common::factorial(elements);

			T denominator = common::factorial(exp);

			return numenator / denominator;
		}

		template <typename T>
		T combinations(T places, T elements)
		{
			if (elements < places)
				return static + _cast<T>(0);

			T numenator = common::factorial(elements);

			T exp = elements - places;

			T pls_factorial = common::factorial(places);

			T denominator = common::factorial(exp) * pls_factorial;

			return numenator / denominator;
		}

		template<typename T>
		rf relative_frequency(T appeared_events, T common_events)
		{
			return static_cast<rf>(appeared_events) / static_cast<rf>(common_events);
		}

		
	}
}

#endif // !COMBINATORICS_HPP
