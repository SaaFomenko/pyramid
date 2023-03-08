#ifndef PYRAMID_H
#define PYRAMID_H


class Pyramid
{
	private:
		int* _arr;
		int _size;

	public:
		int getSize();
		int root();
		void valid_index(int index);
		int from_index(int index);
		int left_index(int parent_index);
		int right_index(int parent_index);
		int parent_index(int child_index);
		int level(int index);

		Pyramid(int* arr, int size);
		~Pyramid();
};

void print_pyramid(Pyramid& pyramid);

#endif
