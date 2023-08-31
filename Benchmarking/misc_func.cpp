//#include"misc_func.hpp"
//
//
//
//
//
//struct SortResult {
//    uint64_t myAlgoTime;
//    uint64_t stdAlgoTime;
//    uint64_t elemCount;
//    uint64_t highestNumber;
//    int randSeed = 51;
//    bool outputMatch;
//};
//
//
//
//
//
//vector<uint64_t> RandomGenerator(SortResult sample) {
//    //this function will return a random generated array of sizes given in an SortResult sample
//    srand(sample.randSeed);
//
//    vector<uint64_t> arr;
//
//    for (uint64_t i = 0; i < sample.elemCount; i++)
//    {
//        arr.push_back((uint64_t)(((float)rand() / RAND_MAX) * (sample.highestNumber - 1)));
//    }
//    return arr;
//}
//
//void print_me(vector<uint64_t> V1) {
//    int ten = 0;
//    for (uint64_t i = 0; i < V1.size(); i++)
//    {
//        cout << V1[i] << " ";
//        ten++;
//        if (ten == 10) {
//            cout << "             " << endl;
//            ten = 0;
//        }
//    }
//}
//
//vector<uint64_t> sortbyhisto(vector<uint64_t>& V1, SortResult& testCase) {
//
//    vector<uint64_t> histo(testCase.highestNumber, 0);
//    for (uint64_t i = 0; i < testCase.elemCount; i++)
//    {
//        histo[V1[i]]++;
//    }
//
//    vector<uint64_t> V2;
//    V2.reserve(testCase.elemCount);
//    for (uint64_t i = 0; i < histo.size(); i++)
//    {
//        while (histo[i] != 0) {
//            V2.push_back(i);
//            histo[i]--;
//        }
//    }
//
//    return V2;
//}
