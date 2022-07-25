#ifndef VECTORS_HPP
# define VECTORS_HPP

# include <iostream>
# include <string>
# include <vector>

template<typename T>
class VecIterator
{
	public:
    typedef T* pointer;
    typedef T const * const_pointer;
    typedef T& reference;
    typedef T const & const_reference;
    typedef std::ptrdiff_t difference_type;
	protected:
		pointer _ptr;
	public:
		VecIterator() : _ptr(nullptr) {};
		VecIterator(T *ptr) : _ptr(ptr) {};
		VecIterator(const VecIterator &it) : _ptr(it._ptr) {};
		VecIterator &operator=(const VecIterator &it) { _ptr = it._ptr; return *this; };
		VecIterator &operator++() { ++_ptr; return *this; };
		VecIterator &operator--() { --_ptr; return *this; };
		VecIterator operator++(int) { VecIterator tmp(*this); ++_ptr; return tmp; };
		VecIterator operator--(int) { VecIterator tmp(*this); --_ptr; return tmp; };
		VecIterator operator+(std::ptrdiff_t n) { VecIterator tmp(*this); tmp._ptr += n; return tmp; };
		VecIterator operator-(std::ptrdiff_t n) { VecIterator tmp(*this); tmp._ptr -= n; return tmp; };
		VecIterator &operator+=(std::ptrdiff_t n) { _ptr += n; return *this; };
		VecIterator &operator-=(std::ptrdiff_t n) { _ptr -= n; return *this; };
		T &operator*() { return *_ptr; };
		T *operator->() { return _ptr; };
		bool operator==(const VecIterator &it) const { return _ptr == it._ptr; };
		bool operator!=(const VecIterator &it) const { return _ptr != it._ptr; };
		bool operator<(const VecIterator &it) const { return _ptr < it._ptr; };
		bool operator>(const VecIterator &it) const { return _ptr > it._ptr; };
		bool operator<=(const VecIterator &it) const { return _ptr <= it._ptr; };
		bool operator>=(const VecIterator &it) const { return _ptr >= it._ptr; };
		std::ptrdiff_t operator-(const VecIterator &it) const { return _ptr - it._ptr; };
		T &operator[](std::ptrdiff_t n) { return _ptr[n]; };
};

template <typename T>
class Vectors: public std::vector<T>
{

	public:
		typedef VecIterator<T> iterator;
		typedef VecIterator<T> const_iterator;
		typedef T* pointer;
   		typedef T const * const_pointer;
		typedef T& reference;
		typedef T const & const_reference;
		typedef std::ptrdiff_t difference_type;
		typedef unsigned long size_type;

		Vectors(){
			std::cout << "Vectors created" << std::endl;
			_vector = new std::vector<T>();
			_vector->push_back(5);
		};
		// Vectors( Vectors const & src );
		// ~Vectors();
		// void begin( void ){ std::cout << "Testing" << std::endl; };
		// typename std::vector<T>::iterator begin( void ){ return std::vector<T>::begin(); };
		// Vectors &		operator=( Vectors const & rhs );
		iterator begin(void) { return iterator(_ptr); };
		// begin();
		void getValue(void) { 			std::cout << _vector->front()<<std::endl;};
	private:
		std::vector<T>	*_vector;
		pointer _ptr;

};
// template <typename T>
// std::ostream &			operator<<( std::ostream & o, Vectors<T> & i );



#endif /* ****************************************************** Vectors_H */