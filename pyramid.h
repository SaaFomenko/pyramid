#ifndef PYRAMID_H
#define PYRAMID_H


class Pyramid
{
	private:
		int* arr;
		int _size;

	public:
		int root();
		int from_index(int index);
		int left_index(int index);
		int right_index(int index);
		int parent_index(int index);
		void valid_index(int index);

		Pyramid(int size, int arr_first, ...);
		~Pyramid();
};

void print_pyramid(Pyramid& pyramid);

#endif
