#include<iostream>
#include"..\Time_Benchmarking\benchmark.hpp"
#include"sorting_mechanisms.hpp"

using namespace std;
bool check(int* array1, int* array2, int lenght)
{
	for (size_t i = 0; i < lenght; i++)
	{
		if (array1[i] != array2[i])
		{
			cout << "Lo jee bhand ho gaya at: "<< i << endl;
			return 0;
		}

	}
	cout << "All good bruh :" << endl;
	return 1;
}

int main() {

	int* wut,* wat,* why,*how,*who;

	sorter<int> hello(1000, 1000);
	wut = hello.insertion_sort();
	wat = hello.bubble_sort();
	why = hello.selection_sort();
	how = hello.sortSTD();
	who = hello.histoSort();
	check(why, who, 1000);
	check(wut, who, 1000);

}