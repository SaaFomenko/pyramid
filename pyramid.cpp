#include <iostream>
#include "pyramid.h"


void print_pyramid(Pyramid pyramid)
{

}

Pyramid::Pyramid(int size, int arr_first, ...) : 
	_size(size),
	arr(&arr_first)
{
//	arr = &arr_first;
}

int Pyramid::root()
{
	return arr[0];
}

int Pyramid::from_index(int index)
{
	valid_index(index);
	return arr[index];
}

void Pyramid::valid_index(int index)
{
	if (index < 0 || _size >= index)
	{
		throw "Error, pyramid index fail!";
	}
}
