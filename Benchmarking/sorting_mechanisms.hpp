#ifndef surtur
#define surtur

#include<algorithm>
#include<cstdlib>
#include<array>
#include<algorithm>
#include<vector>

template<class T>
class sorter{
private:
	T* arr_;
	uint64_t size_of_array;
	uint64_t range_of_array;

	T* rand_gen() {
		srand(100);
		T* inter_array = new T[size_of_array];
		for (uint64_t i = 0; i < size_of_array; i++)
		{
			inter_array[i] = (T)(((float)rand() / RAND_MAX) * (range_of_array - 1));
		}
		return inter_array;
	}



public:
	sorter() {}
	sorter(T* _array_, const uint64_t& _size_, const uint64_t& _range_) :
		arr_(_array_), size_of_array(_size_), range_of_array(_range_) {}
	sorter(const uint64_t& _size_, const uint64_t& _range_) :
		size_of_array(_size_), range_of_array(_range_)
	{
		arr_ = rand_gen();

	}

	uint64_t return_size()
	{
		return this->size_of_array;
	}

	uint64_t return_range()
	{
		return this->range_of_array;
	}

	T* bubble_sort()
	{
		T* temp = new T[size_of_array];
		memcpy(temp, arr_, sizeof(T) * size_of_array);

		bool stop;
		for (uint64_t i = 0; i < size_of_array - 1; i++)
		{
			stop = false;
			for (uint64_t j = 0; j < size_of_array - i - 1; j++)
			{
				if (temp[j] > temp[j + 1])
				{
					swap(temp[j], temp[j + 1]);
					stop = true;
				}
			}

			if (stop == false) {
				break;
			}
		}

		return temp;
	}
	T* recursion_wrapper()
	{
		T* temp = new T[size_of_array];
		memcpy(temp, arr_, size_of_array * sizeof(T));
		selection_sort_recur(temp,size_of_array);
		return temp;
	}

	void bubble_sort_recur(T* ary,int size) 
	{
		if (size == 0)
			return;

		for (uint64_t i = 0; i < size - 1; i++)
		{
			if (ary[i] > ary[i + 1])
				swap(ary[i], ary[i + 1]);
		}

		bubble_sort(ary, size - 1);

	}
	void insertion_sort_recur(T* ary, int size)
	{
		if (size == 1)
			return;

		insertion_sort(ary, size - 1);

		int key = ary[size - 1];
		int iterator = size - 2;

		while (iterator >= 0 && ary[iterator] > key)
		{
			ary[iterator + 1] = ary[iterator];
			iterator--;
		}
		ary[iterator + 1] = key;

	}
	void selection_sort_recur(T* ary, int size)
	{
		if (size == 0)
			return;
		int iterator = 0;
		int key = ary[0];

		for (uint64_t i = 0; i < size; i++)
		{
			if (key > ary[i])
			{
				key = ary[i];
				iterator = i;
			}

		}

		swap(ary[iterator], ary[0]);
		selection_sort_recur(ary + 1, size - 1);


	}
	T* insertion_sort()
	{
		T* temp = new T[size_of_array];
		memcpy(temp, arr_, sizeof(T) * size_of_array);

		int key, j;
		for (uint64_t i = 1; i < size_of_array; i++)
		{
			key = temp[i];
			j = i - 1;

			while (j >= 0 && temp[j] > key)
			{
				temp[j + 1] = temp[j];
				j--;
			}
			temp[j + 1] = key;
		}
		return temp;
	}

	T* selection_sort()
	{
		T* temp = new T[size_of_array];
		memcpy(temp, arr_, sizeof(T) * size_of_array);

		for (uint64_t i = 0; i < size_of_array; i++)
		{
			int key = temp[i];
			int iter;
			bool check = false;
			for (uint64_t j = i + 1; j < size_of_array; j++)
			{
				if (key > temp[j])
				{
					iter = j;
					key = temp[j];
					check = true;
				}

			}
			if (check)
			{
				swap(temp[i], temp[iter]);
			}
		}

		return temp;
	}

	T* sortSTD()
	{
		T* temp = new T[size_of_array];
		memcpy(temp, arr_, sizeof(T) * size_of_array);

		sort(temp, temp + size_of_array);


		return temp;

	}

	T* histoSort()
	{
		vector<T> histogram;
		histogram.resize(range_of_array);

		T* temp = new T[size_of_array];
		memcpy(temp, arr_, sizeof(T) * size_of_array);

		for (uint64_t i = 0; i < size_of_array; i++)
		{
			histogram[temp[i]]++;
		}

		uint64_t iter = 0;
		for (uint64_t i = 0; i < range_of_array; i++)
		{

			for (uint64_t j = 0; j < histogram[i]; j++)
			{
				temp[iter] = i;
				iter++;
			}

		}

		return temp;
	}

	void best_case_gen()
	{
		T* _deleter = arr_;
		arr_ = sortSTD();
		delete _deleter;

	}

	void worst_case_gen()
	{
		sort(arr_ , arr_ + size_of_array,greater<int>());
	}
};



#endif // !surtur

