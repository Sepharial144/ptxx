#include <iostream>

#include "ptxx.hpp"

#include <vector>
#include <iostream>

namespace ptxx {

	class Factorial final
	{
	private:
		enum class factorialStatus
		{
			INIT,
			UNPACKED,
			TRANSFORMED,
		};

		int _number{};
		int _compNum{};

		factorialStatus _status;

		std::vector<int> _set;

		void compute()
		{
			int size = _set.size();
			for (int i = 0; i <= size; ++i)
			{
				_compNum *= _set[i];
			}
		};

		void transform(int limit = 0)
		{
			_set.clear();

			if (_number > limit)
			{
				for (int i = _number; i != limit; --i)
				{
					_set.push_back(i);
				}
			}
			// what will we do if limit <= _number???
		}

	public:
		Factorial() = delete;

		Factorial(int number):
			_number(number),
			_status(factorialStatus::INIT),
			_compNum(1)
		{
			if (common::isPositiveTypename<int> != true)
				throw std::invalid_argument("Used typename is non posititve, you may lost some data");

			if (_number <= 1)
			{
				_number = 1;
			}

			_set.reserve(_number);

			transform();
			_status = factorialStatus::UNPACKED;
			compute();
		};

		~Factorial();

		Factorial& operator / (Factorial& other)
		{
			if (_status != factorialStatus::TRANSFORMED && other._status != factorialStatus::TRANSFORMED)
			{
				transform(other._number);
				_status = factorialStatus::TRANSFORMED;
				compute();

				other._number = 1;
				other._status = factorialStatus::TRANSFORMED;
			}
			else {
				throw std::exception("Could not apply action to expression Factorial / Factorial");
			}
		}

		friend std::ostream& operator << (std::ostream& os, Factorial& el)
		{
			os << el._compNum;
			return os;
		}

		std::size_t operator = (std::size_t)
		{
			return static_cast<std::size_t>(_compNum);
		}
	};


} //!ptxx


int main(int argc, char *argv[])
{
	std::cout << "ptxx" << std::endl;
	std::cout << "add test branch" << std::endl;

	ptxx::Factorial num(3);

	std::cout << num << std::endl;

	system("PAUSE");
	return 0;
}