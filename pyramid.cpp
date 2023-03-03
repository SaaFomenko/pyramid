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
	
	int parent_index = index;
	int left_index = pyramid.left_index(parent_index);
	int right_index = pyramid.right_index(parent_index);
	int child_index[] = {
		left_index, 
		right_index,
	};
	int size = sizeof(child_index) / sizeof(child_index[0]);
	
	for (int i = 0; i < size; ++i)
	{
		if (child_index[i] > 0)
		{
			const char* lable = i == 0 ? left_lable : right_lable;
      
			std::cout << pyramid.level(child_index[i]) << lable << 
				pyramid.from_index(parent_index) << ") " << 
				pyramid.from_index(child_index[i]) << std::endl;
		}
	}
		
	if (left_index > 0)
	{
		print_pyramid(pyramid, child_index[left_index]);
	}
	if (right_index > 0)
	{
		print_pyramid(pyramid, child_index[right_index]);
	}
}

Pyramid::Pyramid(int* arr, int size) : 
	_size(size)
{
	_arr = new int[size];

	for (int i = 0; i < _size; ++i)
	{
		_arr[i] = arr[i];
	}
}

Pyramid::~Pyramid()
{
	delete[] _arr;
	_arr = nullptr;
}	

int Pyramid::root()
{
	return _arr[0];
}

void Pyramid::valid_index(int index)
{
	if (index < 0 || _size <= index)
	{
		std::cout << "Index: " << index << std::endl;
		throw "Error, pyramid index fail!";
	}
}

int Pyramid::from_index(int index)
{
	valid_index(index);
	return _arr[index];
}

int Pyramid::left_index(int parent_index)
{
	valid_index(parent_index);

	int index = 2 * parent_index + 1;

	std::cout << "Index left: " << index << std::endl;
	if (index >= _size)	
		return -1;

	return index;
}

int Pyramid::right_index(int parent_index)
{
	valid_index(parent_index);
	
	int index = 2 * parent_index + 2;

	std::cout << "Index right: " << index << std::endl;
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

	return i;
}
