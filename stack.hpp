#ifndef STACK_HPP
#define STACK_HPP
#include <string>
#include<iostream>
#include < exception >

class StackOverflow : public std::exception
{
public:
	StackOverflow() : reason_("Stack Overflow") {}
	const char* what() const noexcept override { return reason_.c_str(); }
private:
	const std::string reason_;
};

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason_("Stack Underflow") {}
	const char* what() const noexcept override { return reason_.c_str(); }
private:
	const std::string reason_;
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Wrong Stack Size") {}
	const char* what() const noexcept override { return reason_.c_str(); }
private:
	const std::string reason_;
};

template <typename T>
class StackArray
{
public:
	StackArray(int size );
	StackArray(const StackArray& other);
	~StackArray();
	bool isEmpty() { return top_ == 0; };
	const StackArray& operator = (const StackArray& other);
	void push(T item);
	T pop();
	T top() const;
	bool full() const;
private:
	std::size_t size_;
	std::size_t top_;
	T* arr_;
};

template <typename T>
StackArray<T>::StackArray(int size) :
	size_(size),
	top_(0),
	arr_(nullptr)
{
	if (size_  == 0) {  // std::size_t is always positive or 0
		throw WrongStackSize();
	}
	else {
              try
              {
		arr_ = new T[size_];
	     } catch (std::bad_alloc) // to large size, not enough memory, standard exception occurs
	     {
                throw WrongStackSize(); // throw our custom exception
	     }
}

template<typename T>
StackArray<T>::StackArray(const StackArray& other)
{
	size_ = other.size_;
	top_ = other.top_;
	arr_ = new T[size_];
	{}
}




template <typename T>
StackArray<T>::~StackArray()
{
	delete[] arr_;
}

template <typename T>
void StackArray<T>::push(T item)
{
	if (top_ >= size_) {
		throw StackOverflow();
	}
	arr_[top_++] = item;
}

template<typename T>
T StackArray<T>::pop()
{
	if (isEmpty()) {
		throw StackUnderflow();
	}
	return arr_[--top_];
}

template<typename T>
const StackArray<T>& StackArray<T>::operator=(const StackArray& other)
{
	size_ = other.size_;
	top_ = other.top_;
	arr_ = new T[size_];
	return *this;

}
template<typename T>
bool StackArray<T>::full() const
{
	return top_ == size_;
}
template<typename T>
T StackArray<T>::top() const {
	if (top_ == 0) {
		throw StackUnderflow();
	}
	else {
		return arr_[top_ - 1];
	}
}
#endif // ! STACK_HPP
