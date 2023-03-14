#include <iostream>
#include "../pyramid.h"

void print_arr(int* arr, int size)
{
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	const std::string pyramid_lable = "Пирамида:";
	int index = 0;
	char cmd[6];

// Test array
	int arr[] = { 1, 3, 6, 5, 9, 8 };
//	int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
//	int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	int size = sizeof(arr) / sizeof(arr[0]);


	Pyramid pyramid(arr, size);

	try
	{
		print_arr(arr, size);
		std::cout << pyramid_lable << std::endl;
		print_pyramid(pyramid);
		std::cout << std::endl;
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}

	do
	{
		std::cout << "Вы находитесь здесь: ";
		print_block(pyramid, index);
		
		std::cout << "Введите команду: ";
		std::cin >> cmd;
		explorer_pyramid(pyramid, cmd, index);
	} 
	while (index < 0);

	return 0;
}
