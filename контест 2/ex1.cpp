#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>

int main()
{
	int n;
	int sum = 0;
	std::cin >> n;

	std::vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}

	double mean = std::accumulate(v.begin(), v.end(), 0.0) / v.size();

	for (int a : v)
	{
		if (a > mean)
		{
			sum += a;
		}
	}

	std::cout << sum;

	return 0;
}
