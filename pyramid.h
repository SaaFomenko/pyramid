#ifndef PYRAMID_H
#define PYRAMID_H

template<typename T>

class Pyramid
{
	private:
		T* arr;
		int size;

	public:
		T root(int index);
		T from_index(int index);
		T left_index(int index);
		T right_index(int index);
		T parent_index(int index);

		Pyramid(int size, T ...);
		~Pyramid();
};

void print_pyramid(Pyramid& pyramid);

#endif
