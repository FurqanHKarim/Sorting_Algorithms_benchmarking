#ifndef ultra_sort
#define ultra_sort
#include"sorting_mechanisms.hpp"
#include"..\Time_Benchmarking\benchmark.hpp"
#include<fstream>


template<class T>
class ultra_sort_bench {
private:
	sorter<T> ogMechanism;
	TimeUtility timeKeeper[5];



public:
	ultra_sort_bench(T* _array_, const uint64_t& _size_, const uint64_t& _range_) {
		ogMechanism = sorter<T>(_array_, _size_, _range_);
	}

	ultra_sort_bench(const uint64_t& _size_, const uint64_t& _range_) 
	{
		ogMechanism = sorter<T>(_size_, _range_);
	}


	/// !Summary 0 == bubble sort
	/// 1 == insertion, 2==selection,3 == STDsort, 4== histo 
	/// 
	T* test_bubble() {
		T* intermidiate;
		timeKeeper[0].startBenchmark();
		intermidiate = ogMechanism.bubble_sort();
		timeKeeper[0].endBenchmark();
		return intermidiate;
	}

	T* test_insertion() {
		T* intermidiate;
		timeKeeper[1].startBenchmark();
		intermidiate = ogMechanism.insertion_sort();
		timeKeeper[1].endBenchmark();
		return intermidiate;
	}

	T* test_selection() {
		T* intermidiate;
		timeKeeper[2].startBenchmark();
		intermidiate = ogMechanism.selection_sort();
		timeKeeper[2].endBenchmark();
		return intermidiate;
	}

	T* test_STDsort() {
		T* intermidiate;
		timeKeeper[3].startBenchmark();
		intermidiate = ogMechanism.sortSTD();
		timeKeeper[3].endBenchmark();
		return intermidiate;
	}

	T* test_histo() {
		T* intermidiate;
		timeKeeper[4].startBenchmark();
		intermidiate = ogMechanism.histoSort();
		timeKeeper[4].endBenchmark();
		return intermidiate;
	}
	
	/// !Summary 0 == bubble sort
	/// 1 == insertion, 2==selection,3 == STDsort, 4== histo 
	void display_result(string prefix)
	{
		cout << "Test with parameters: Size = " << ogMechanism.return_size() << ", Range = " << ogMechanism.return_range() << endl;
		cout << "Bubble Sort    "; timeKeeper[0].dispBenchmark(prefix);
		cout << "Insertion Sort "; timeKeeper[1].dispBenchmark(prefix);
		cout << "Selection Sort "; timeKeeper[2].dispBenchmark(prefix);
		cout << "STD Sort       "; timeKeeper[3].dispBenchmark(prefix);
		cout << "Histogram Sort "; timeKeeper[4].dispBenchmark(prefix);
		
	}
	void test_all()
	{
		test_bubble();
		test_insertion();
		test_selection();
		test_STDsort();
		test_histo();

	}

	/// !Summary 
	/// 0 == bubble sort, 1 == insertion, 2==selection,3 == STDsort, 4== histo 
	/// 
	void csv_out(string file_name) 
	{
		test_all();
		fstream file(file_name+".csv", ios::out | ios::app);
		file << ogMechanism.return_size() << ","
			<< ogMechanism.return_range() << ",";
		
		for (int i = 0; i < 5; i++)
		{
			file << timeKeeper[i].return_Benchmark() << ",";
		}

		file << "\n";
		file.close();

	}
	void initialize_csv(string file_name)
	{
		fstream file(file_name + ".csv", ios::out | ios::trunc);
		file << "Size,Range,Bubble Sort,Insertion sort,Selection,STD sort,Histogram sort \n";
		file.close();
	}

	void generate_best_case()
	{
		ogMechanism.best_case_gen();
	}

	void generate_worst_case()
	{
		ogMechanism.worst_case_gen();
	}
};
#endif // !ultra_sort
