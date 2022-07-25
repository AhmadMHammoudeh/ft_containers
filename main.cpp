#include "Vectors.hpp"


int main()
{
	std::vector<int>					v;
	// iterator<int> it(v.begin());
	Vectors<int> v2;
	int a;

	// v2 = v;
	
	Vectors<int>::iterator it = v2.mbegin();
	Vectors<int>::iterator ite = v2.mend();
	// std::cout << v2 << std::endl;
	std::cout << "Value : " << std::endl;
	// v2.getValue();
	// v2.getValueB();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, "\n"));
	// for (i)
	// a = *it;
	// std::cout << it.operator[](0) << std::endl;
	// std::cout << a << std::endl;
	// *v2; 
}
