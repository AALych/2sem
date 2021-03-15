#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	int *c = &a;
	int *d = &b;
	std::cout << do_some_awesome_work(c, d) << std::endl;
	return 0;
}
