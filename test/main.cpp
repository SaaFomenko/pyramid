#include <iostream>
#include "../pyramid.h"


int main()
{

// Test array
	int arr[] = { 1, 3, 6, 5, 9, 8 };
//	int arr[] = { 94, 67, 18, 44, 44, 12, 6, 42 };
//	int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	int size = sizeof(arr) / sizeof(arr[0]);


	std::cout << "Исходный массив: ";

	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;


	Pyramid pyramid(arr, size);

	try
	{
		print_pyramid(pyramid, size);
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}

	return 0;
}
