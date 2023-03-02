#ifndef PYRAMID_H
#define PYRAMID_H


class Pyramid
{
	private:
		int* arr;
		int _size;

	public:
		int root();
		void valid_index(int index);
		int from_index(int index);
		int left_index(int parent_index);
		int right_index(int parent_index);
		int parent_index(int child_index);
		int level(int index);

		Pyramid(int size, int arr_first, ...);
		~Pyramid();
};

void print_pyramid(Pyramid& pyramid, int index);

#endif
