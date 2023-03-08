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

// Test array
	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size3 = sizeof(arr3) / sizeof(arr3[0]);

	Pyramid pyramid1(arr1, size1);
	Pyramid pyramid2(arr2, size2);
	Pyramid pyramid3(arr3, size3);

	try
	{
		print_arr(arr1, size1);
		print_pyramid(pyramid1);
		std::cout << std::endl;

		print_arr(arr2, size2);
		print_pyramid(pyramid2);
		std::cout << std::endl;

		print_arr(arr3, size3);
		print_pyramid(pyramid3);
		std::cout << std::endl;
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}

	return 0;
}
