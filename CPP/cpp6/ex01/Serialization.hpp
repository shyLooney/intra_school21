#ifndef __SERIALIZATION_HPP__
#define __SERIALIZATION_HPP__

#include <cstdint>
#include <iostream>

struct Data
{
	unsigned int	num;
};

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

#endif