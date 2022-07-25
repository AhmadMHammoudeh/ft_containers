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
		T *operator->() { return *_ptr; };
		bool operator==(const VecIterator &it) const { return _ptr == it._ptr; };
		bool operator!=(const VecIterator &it) const { return _ptr != it._ptr; };
		bool operator<(const VecIterator &it) const { return _ptr < it._ptr; };
		bool operator>(const VecIterator &it) const { return _ptr > it._ptr; };
		bool operator<=(const VecIterator &it) const { return _ptr <= it._ptr; };
		bool operator>=(const VecIterator &it) const { return _ptr >= it._ptr; };
		std::ptrdiff_t operator-(const VecIterator &it) const { return _ptr - it._ptr; };
		T &operator[](std::ptrdiff_t n) { return _ptr[n]; };
};

template<
    class T,
    class Allocator = std::allocator<T>
>
class Vectors: public std::vector<T>
{

	public:
		typedef T value_type;
		typedef VecIterator<T> iterator;
		typedef VecIterator<T> const_iterator;
		typedef iterator* iterator_ptr;
		typedef T* pointer;
   		typedef T const * const_pointer;
		typedef T& reference;
		typedef T const & const_reference;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

		Vectors(): _ptr(nullptr), m_size(0) {
			std::cout << "Vectors created" << std::endl;
		};
		void assign(size_type count, const T &value){

		};
		template <class InputIt>
		void assign(InputIt first, InputIt last){};
		// void assign( std::initializer_list<T> ilist ){};
		void reserve( size_type new_cap ){
			if (new_cap > max_size())
				throw std::length_error("Vectors::reserve : new_cap > max_size()");
			if (new_cap > this->capacity())
			{
				T *tmp = new T[new_cap];
				std::copy(this->begin(), this->end(), tmp);
				delete[] this->_ptr;
				this->_ptr = tmp;
				this->m_capacity = new_cap;
			}
		}
		bool empty() const{
			return this->size() == 0;
		}
		size_type size() const{
			return m_size;
		}
		size_type max_size() const {
			return (size_type)std::numeric_limits<size_type>::max();
		}
		size_type capacity() const{
			return (this->_ptr == nullptr ? 0 : this->m_capacity);
		}
		void insert(iterator it, T value)
		{
			m_size += 1;
			_ptr = vec_alloc.allocate(1);
			difference_type t = &(*it) - &(*this->begin());
			std::cout << "Distance" << t << std::endl;
			vec_alloc.construct(&_ptr[t], value);
			std::cout << "Vectors insert" << _ptr[t] << std::endl;
		};
		void clear(){
			vec_alloc.deallocate(_ptr, m_size);
			m_size = 0;
		};
		iterator erase(iterator it){
			vec_alloc.destroy(&_ptr[it - &(*this->begin())]);
			vec_alloc.deallocate(&_ptr[it - &(*this->begin())], 1);
			m_size -= 1;
			return it;
		}
		iterator erase( iterator first, iterator last ){
			difference_type t = &(*first) - &(*this->begin());
			difference_type t2 = &(*last) - &(*this->begin());
			vec_alloc.destroy(&_ptr[t], &_ptr[t2]);
			vec_alloc.deallocate(&_ptr[t], t2 - t);
			m_size -= t2 - t;
			return first;
		}
		// Vectors( Vectors const & src );
		// ~Vectors();
		// void begin( void ){ std::cout << "Testing" << std::endl; };
		// typename std::vector<T>::iterator begin( void ){ return std::vector<T>::begin(); };
		// Vectors &		operator=( Vectors const & rhs );
		iterator mbegin(void) { return iterator(_ptr); };
		// iterator begin(void) const { return iterator(_ptr); };
		iterator mend(void) { return iterator(_ptr + m_size); };
		// iterator end(void) const { return iterator(_ptr + _vector->size()); };
		// begin();
		// void getValue(void) { 			std::cout << _vector->front()<<std::endl;};
		// void getValueB(void) { 			std::cout << _vector->back()<<std::endl;};
	private:
		pointer _ptr;
		size_type m_capacity;
		size_type m_size;
		Allocator vec_alloc;

};
// template <typename T>
// std::ostream &			operator<<( std::ostream & o, Vectors<T> & i );



#endif /* ****************************************************** Vectors_H */
