#include <iostream>
#include "pyramid.h"

static const char* root_lable = " root ";
static const char* left_lable = " left(";
static const char* right_lable = " right(";

void print_pyramid(Pyramid& pyramid, int index)
{ 
	if (index < 0)
	{
		return;
	}

	if (index == 0)
	{
		std::cout << index << root_lable << pyramid.root() << std::endl;
	}
	else
	{
		int left_index = pyramid.left_index(index);
		if (left_index > 0)
		{
			std::cout << pyramid.level(index) << left_lable << 
				pyramid.from_index(index) << ") " << 
				pyramid.from_index(left_index) << std::endl;
			print_pyramid(pyramid, left_index);
		}

		int right_index = pyramid.right_index(index);
		if (right_index > 0)
		{
			std::cout << pyramid.level(index) << right_lable << 
				pyramid.from_index(index) << ") " << 
				pyramid.from_index(right_index) << std::endl;
			print_pyramid(pyramid, right_index);
		}
	}
}

Pyramid::Pyramid(int size, int arr_first, ...) : 
	_size(size),
	arr(&arr_first)
{
//	arr = &arr_first;
}

Pyramid::~Pyramid()
{}	

int Pyramid::root()
{
	return arr[0];
}

void Pyramid::valid_index(int index)
{
	if (index < 0 || _size >= index)
	{
		throw "Error, pyramid index fail!";
	}
}

int Pyramid::from_index(int index)
{
	valid_index(index);
	return arr[index];
}

int Pyramid::left_index(int parent_index)
{
	valid_index(parent_index);

	int index = 2 * parent_index + 1;

	if (index >= _size)	
		return -1;

	return index;
}

int Pyramid::right_index(int parent_index)
{
	valid_index(parent_index);
	
	int index = 2 * parent_index + 2;

	if (index >= _size)
		return -1;
	
	return index;
}

int Pyramid::parent_index(int child_index)
{
	valid_index(child_index);
	
	return (child_index - 1) / 2;
}

int Pyramid::level(int index)
{
	valid_index(index);

	if (index == 0)
		return 0;

	int i = 0;

	while (index > 0)
	{
		index = parent_index(index);
		++i;
	}

	return i + 1;
}