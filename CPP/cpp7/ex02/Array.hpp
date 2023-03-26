#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>


template<class T>
class Array
{
private:
	T* arr;
	unsigned int n;
public:
	Array();
	Array(const Array&);
	~Array();
	Array& operator=(const Array<T>&);

	unsigned int size() const;
	Array(unsigned int);
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif