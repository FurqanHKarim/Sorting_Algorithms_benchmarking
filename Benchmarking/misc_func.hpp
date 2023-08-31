#include <iostream>
#include <cstdlib>
#include <fstream>
#include <array>
#include <list>
#include<vector>
#include<chrono>
#include <algorithm>    // std::sort
using namespace std;


struct SortResult;
vector<uint64_t> RandomGenerator(SortResult sample);
vector<uint64_t> sortbyhisto(vector<uint64_t>& V1, SortResult& testCase);
void print_me(vector<uint64_t> V1);
SortResult SortStuff(uint64_t elemCount, uint64_t highestNumber);


class 