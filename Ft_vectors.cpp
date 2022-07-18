#include "Ft_vectors.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ft_vectors::Ft_vectors()
{
}

Ft_vectors::Ft_vectors( const Ft_vectors & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ft_vectors::~Ft_vectors()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ft_vectors &				Ft_vectors::operator=( Ft_vectors const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ft_vectors const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */