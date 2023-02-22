#include <iostream>
#include "../pyramid.h"


int main()
{
	const std::string array_lable = "Исходный массив: ";
	const std::string pyramid_lable = "Пирамида: ";

// Test array
	int arr[] = { 1, 3, 6, 5, 9, 8 };
//	int arr[] = { 94, 67, 18, 44, 44, 12, 6, 42 };
//	int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	int size = sizeof(arr) / sizeof(arr[0]);

	Pyramid pyrmid(arr, size);

	print_pyramid(pyramid);

	return 0;
}
