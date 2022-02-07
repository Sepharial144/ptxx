#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <iterator>
#include <typeinfo>

namespace pt 
{
	namespace common 
	{
		unsigned int factorial(unsigned int& num_el) 
		{
			unsigned int result = 1;

			if (num_el == 0) return 1;

			for (unsigned int i = 0; i <= num_el; ++i)
			{
				result = result * i;
			}
			return result;
		}

		template<typename T>
		bool checkVariable(T variable) 
		{
			if (typeid(T).name() == typeid(float).name()) 
				return true;

			if (typeid(T).name() == typeid(double).name()) 
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

#endif // COMBINATORICS_H
