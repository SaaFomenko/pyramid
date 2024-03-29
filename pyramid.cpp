#include <iostream>
#include <string.h>
#include "pyramid.h"

static const char* root_lable = " root ";
static const char* left_lable = " left(";
static const char* right_lable = " right(";
static const char* negative_warn = "Warning: Index do not can negative!";
static const char* more_num_warn = "Warning: Index do not can more numbers blocks!";
static const int root_level = 0;

void print_block(Pyramid& pyramid, int index)
{
	if (index < 0)
	{
		std::cout << negative_warn << std::endl;
		return;
	}

	if (index == 0)
	{
		std::cout << root_level << root_lable << pyramid.root() << std::endl;
		return;
	}

	int pyramid_size = pyramid.getSize();

	if (index >= pyramid_size)
	{
		std::cout << more_num_warn << std::endl;
		return;
	}

	int parent_index = pyramid.parent_index(index);
	const char* lable = (index % 2) == 0 ? right_lable : left_lable;

	std::cout << pyramid.level(index) << lable << 
		pyramid.from_index(parent_index) << ") " << 
		pyramid.from_index(index) << std::endl;
}

bool equal_char(const char* str1, const char* str2)
{
	return strcmp(str1, str2) == 0 ? true : false;
}

void explorer_pyramid(Pyramid& pyramid, const char* cmd, int& index)
{
	const char* div = ", ";
	const char* up_cmd = "up";
	const char* left_cmd = "left";
	const char* right_cmd = "right";
	const char* exit_cmd = "exit";
	const char* succes = "Ok";
	const std::string err = "Ошибка! Отсутствует ";
	const std::string parent_lable = "родитель";
	const std::string left_lable = "левый потомок";
	const std::string right_lable = "правый потомок";
	const std::string cmd_err = " - Неверно введа команда, для перехода введите: ";

	if (equal_char(cmd, exit_cmd))
	{
		index = -2;
		return;
	}

	if (equal_char(cmd, up_cmd))
	{
		if (index == 0)
		{
			std::cout << err << parent_lable << std::endl;
			return;
		}

		index = pyramid.parent_index(index);
		std::cout << succes << std::endl;
		return;
	}

	if (equal_char(cmd, right_cmd))
	{
		int r = pyramid.right_index(index);

		if (r == -1)
		{
			std::cout << err << right_lable << std::endl;
			return;
		}

		index = r;
		std::cout << succes << std::endl;
		return;
	}

	if (equal_char(cmd, left_cmd))
	{
		int l = pyramid.left_index(index);

		if (l == -1)
		{
			std::cout << err << left_lable << std::endl;
			return;
		}

		index = l;
		std::cout << succes << std::endl;
		return;
	}

	std::cout << cmd << cmd_err << std::endl;
	std::cout << up_cmd << div << right_cmd << div << right_cmd <<
	 div << exit_cmd << std::endl;
	return;	
}

void print_pyramid(Pyramid& pyramid)
{ 
	int pyramid_size = pyramid.getSize();

	for (int i = 0; i < pyramid_size; ++i)
	{
		print_block(pyramid, i);
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

int Pyramid::getSize()
{
	return _size;
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

//	std::cout << "Index left: " << index << std::endl;
	if (index >= _size)	
		return -1;

	return index;
}

int Pyramid::right_index(int parent_index)
{
	valid_index(parent_index);
	
	int index = 2 * parent_index + 2;

//	std::cout << "Index right: " << index << std::endl;
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
