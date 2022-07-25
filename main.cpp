#include "Vectors.hpp"


int main()
{
	std::vector<int>					v;
	// iterator<int> it(v.begin());
	Vectors<int> v2;
	int a;

	// v2 = v;
	
	Vectors<int>::iterator it = v2.mbegin();
	// std::cout << v2 << std::endl;
	v2.insert(it, 1);
	v2.insert(++it, 2);
	// v2.insert(++it, 2);
	// v2.insert(it + 1, 1);
	it = v2.mbegin();
	Vectors<int>::iterator ite = v2.mend();
	// std::cout << "Value : " << std::endl;
	// v2.getValue();
	// v2.getValueB();
	// it++;
	for (;it != ite; ++it)
	{
		std::cout << "Values : "<< *it << std::endl;
	}
	// std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, "\n"));
	// for (i)
	// a = *it;
	// std::cout << it.operator[](0) << std::endl;
	// std::cout << a << std::endl;
	// *v2; 
}
