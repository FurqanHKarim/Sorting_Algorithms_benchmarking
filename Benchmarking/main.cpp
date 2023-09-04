#include<iostream>
#include"..\Time_Benchmarking\benchmark.hpp"
#include"sorting_mechanisms.hpp"
#include"ultra_sort_bench.hpp"

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



	
	vector<ultra_sort_bench<int>> random;
	vector<ultra_sort_bench<int>>  best_cases;
	vector<ultra_sort_bench<int>> worst_cases;

	random.push_back(ultra_sort_bench<int>(1, 1));
	random[0].initialize_csv("results_for_random");
	
	best_cases.push_back(ultra_sort_bench<int>(1, 1));
	best_cases[0].initialize_csv("results_for_best_cases");


	worst_cases.push_back(ultra_sort_bench<int>(1, 1));
	worst_cases[0].initialize_csv("results_for_worst_cases");


	//making a big array
	for (int j = 10; j < (100); j *= 10)
	{
		for (int i = 10; i < (100000); i *= 2)
		{
			
			random.push_back(ultra_sort_bench<int>(i, j));
			best_cases.push_back(ultra_sort_bench<int>(i, j));
			best_cases[best_cases.size()-1].generate_best_case();
			worst_cases.push_back(ultra_sort_bench<int>(i, j));
			worst_cases[worst_cases.size()-1].generate_best_case();
		}
		
	}

	
	//cout << "Sup Jani" << endl;

	for (uint64_t i = 0; i < random.size(); i++)
	{
		random[i].test_all();
		random[i].csv_out("results_for_random");
		random[i].display_result("ns");

		/*best_cases[i].test_all();
		best_cases[i].csv_out("results_for_best_cases");
		best_cases[i].display_result("ns");

		worst_cases[i].test_all();
		worst_cases[i].csv_out("results_for_worst_cases");
		worst_cases[i].display_result("ns");*/

	}
	//random[0].csv_out();
	random[0].display_result("ns");

}