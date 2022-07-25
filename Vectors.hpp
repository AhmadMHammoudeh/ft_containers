#ifndef VECTORS_HPP
# define VECTORS_HPP

# include <iostream>
# include <string>
# include <vector>

template<typename T>
class iterator : public std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>
{
	public:
    typedef T* pointer;
    typedef T const * const_pointer;
    typedef T& reference;
    typedef T const & const_reference;
    typedef std::ptrdiff_t difference_type;
	pointer _ptr;
	public:
		iterator() : _ptr(nullptr) {};
		iterator(T *ptr) : _ptr(ptr) {};
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
		T &operator*() { return *_ptr; };
		T *operator->() { return _ptr; };
		bool operator==(const iterator &it) const { return _ptr == it._ptr; };
		bool operator!=(const iterator &it) const { return _ptr != it._ptr; };
		bool operator<(const iterator &it) const { return _ptr < it._ptr; };
		bool operator>(const iterator &it) const { return _ptr > it._ptr; };
		bool operator<=(const iterator &it) const { return _ptr <= it._ptr; };
		bool operator>=(const iterator &it) const { return _ptr >= it._ptr; };
		std::ptrdiff_t operator-(const iterator &it) const { return _ptr - it._ptr; };
		T &operator[](std::ptrdiff_t n) { return _ptr[n]; };
};

template <typename T>
class Vectors
{

	public:

		Vectors();
		Vectors( Vectors const & src );
		~Vectors();
		std::iterator<std::random_access_iterator_tag, T>	begin( void ){i++;};
		std::iterator<std::random_access_iterator_tag, T>	begin( void ) const;
		Vectors &		operator=( Vectors const & rhs );

	private:
		std::vector<T>	_vect;


};

// std::ostream &			operator<<( std::ostream & o, Vectors const & i );

#endif /* ****************************************************** Vectors_H */