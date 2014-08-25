#include "../src/mSort.hpp"
#include <iostream>

int main()
{
	int a[] = {1,6,2,3,8,21,43,0,7};
	int length = 9;

	mSort(a, 0, length);

	for(int i = 0; i < length; i++)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;

}
