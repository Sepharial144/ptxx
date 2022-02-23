#ifndef SCHEME_HPP
#define SCHEME_HPP

struct Scheme
{
	std::vector<std::vector<int>> _sc;
	std::vector<int> _sc_filter;
	unsigned int _scsize{}; // it is for filter what is 
	int _sc_max_size{};

	Scheme() {};

	void init(int data_size)
	{
		std::vector<int> temp;

		sizeScheme(data_size);

		_sc_max_size = data_size;
		_sc.reserve(_scsize);
		_sc_filter.reserve(_scsize);

		backtrackIndices(0, data_size, temp);

		sortScheme();
	}

	void sizeScheme(int& sz)
	{
		_scsize = 1;
		for (int i = 1; i != sz + 1; ++i)
			_scsize *= i;
	}

	void backtrackIndices(int idx, int& data_size, std::vector<int>& temp)
	{
		std::sort(temp.begin(), temp.end()); // need refactoring

		if (idx == data_size)
		{
			_sc.push_back(temp);
		}
		else
		{
			temp.push_back(idx);
			backtrackIndices(idx + 1, data_size, temp);

			temp.pop_back();
			backtrackIndices(idx + 1, data_size, temp);
		}
	}

	void sortScheme()
	{
		std::sort(_sc.begin(), _sc.end(),
			[](std::vector<int>& a, std::vector<int>& b) {
				return a.size() < b.size();
			});
	}
};

#endif // !SCHEME_HPP