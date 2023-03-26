#include "Array.hpp"

template<class T>
unsigned int Array<T>::size() const {return n;}

template<class T>
Array<T>::Array()
{
	n = 0;
	arr = nullptr;
}

template<class T>
Array<T>::Array(const Array<T>& elem)
{
	*this = elem;
}

template<class T>
Array<T>::~Array()
{
	delete arr;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& elem)
{
	n = elem.size();
	arr = new T[n];
	for (std::size_t i = 0; i < n; i++)
		arr[i] = elem[i];
	return *this;
}

template<class T>
Array<T>::Array(unsigned int index)
{
	n = index;
	arr = new T[n];
}

template<class T>
T& Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= n)
		throw(std::exception());
	return arr[index];
}

template<class T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= n)
		throw(std::exception());
	return arr[index];
}