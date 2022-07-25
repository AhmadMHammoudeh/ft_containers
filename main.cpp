#include "Vectors.hpp"


int main()
{
	std::vector<int>					v;
	// iterator<int> it(v.begin());
	Vectors<int> v2;
	int a;

	// v2 = v;
	
	Vectors<int>::iterator it = v2.begin() + 1;
	// std::cout << v2 << std::endl;
	v2.getValue();
	a = *it;
	// std::cout << it.operator[](0) << std::endl;
	std::cout << a << std::endl;
	// *v2; 
}