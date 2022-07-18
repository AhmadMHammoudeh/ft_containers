#ifndef FT_VECTORS_HPP
# define FT_VECTORS_HPP

# include <iostream>
# include <string>
# include <vector>

template<typename Vector>
class iterator : public std::iterator<std::random_access_iterator_tag, Vector, std::ptrdiff_t, Vector*, Vector&>
{
	public:
		iterator() : _ptr(nullptr) {};
		iterator(Vector *ptr) : _ptr(ptr) {};
		iterator(const iterator &it) : _ptr(it._ptr) {};
		iterator &operator=(const iterator &it) { _ptr = it._ptr; return *this; };
		iterator &operator++() { ++_ptr; return *this; };
		iterator &operator--() { --_ptr; return *this; };
		iterator operator++(int) { iterator tmp(*this); ++_ptr; return tmp; };
		iterator operator--(int) { iterator tmp(*this); --_ptr; return tmp; };
		iterator operator+(std::ptrdiff_t n) { iterator tmp(*this); tmp._ptr += n; return tmp; };
		iterator operator-(std::ptrdiff_t n) { iterator tmp(*this); tmp._ptr -= n; return tmp; };
		iterator &operator+=(std::ptrdiff_t n) { _ptr += n; return *this; };
		iterator &operator-=(std::ptrdiff_t n) { _ptr -= n; return *this; };
		Vector &operator*() { return *_ptr; };
		Vector *operator->() { return _ptr; };
		bool operator==(const iterator &it) const { return _ptr == it._ptr; };
		bool operator!=(const iterator &it) const { return _ptr != it._ptr; };
		bool operator<(const iterator &it) const { return _ptr < it._ptr; };
		bool operator>(const iterator &it) const { return _ptr > it._ptr; };
		bool operator<=(const iterator &it) const { return _ptr <= it._ptr; };
		bool operator>=(const iterator &it) const { return _ptr >= it._ptr; };
		std::ptrdiff_t operator-(const iterator &it) const { return _ptr - it._ptr; };
		Vector &operator[](std::ptrdiff_t n) { return _ptr[n]; };
};

template <typename T>
class Ft_vectors
{

	public:

		Ft_vectors();
		Ft_vectors( Ft_vectors const & src );
		~Ft_vectors();
		std::iterator<std::random_access_iterator_tag, T>	begin( void ){i++;};
		std::iterator<std::random_access_iterator_tag, T>	begin( void ) const;
		Ft_vectors &		operator=( Ft_vectors const & rhs );

	private:
		std::vector<T>	_vect;


};

std::ostream &			operator<<( std::ostream & o, Ft_vectors const & i );

#endif /* ****************************************************** FT_VECTORS_H */