#include<algorithm>
#include<cstdlib>
#include<array>

template<class T>
class sorter 
{
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


	

	T* bubble_sort()
	{
		T* temp = new T[size_of_array];
		memcpy(temp, arr_,sizeof(T)*size_of_array);

		bool stop;
		for (uint64_t i = 0; i < size_of_array-1; i++)
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
};