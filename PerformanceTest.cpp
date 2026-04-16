#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>
#include <vector>
#include "BinaryHeap.h"

using namespace std;
using namespace std::chrono;

struct TestResult {
    int dataSize;
    double insertTime;
    double extractMinTime;
    double totalTime;
};

vector<int> generateRandomData(int size, int seed = 42) {
    vector<int> data;
    mt19937 gen(seed);
    uniform_int_distribution<> dis(1, 1000000);
    
    for (int i = 0; i < size; i++) {
        data.push_back(dis(gen));
    }
    return data;
}

TestResult testBinaryHeap(int size) {
    TestResult result;
    result.dataSize = size;
    
    auto data = generateRandomData(size);
    BinaryHeap<int> heap;

    auto start = high_resolution_clock::now();
    for (int val : data) {
        heap.insert(val);
    }
    auto end = high_resolution_clock::now();
    result.insertTime = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    while (!heap.isEmpty()) {
        heap.extractMin();
    }
    end = high_resolution_clock::now();
    result.extractMinTime = duration_cast<microseconds>(end - start).count();
    
    result.totalTime = result.insertTime + result.extractMinTime;
    
    return result;
}

void printResults(const vector<TestResult>& results) {
    cout << "\n" << string(80, '=') << endl;
    cout << "BINARY HEAP PERFORMANCE TEST RESULTS" << endl;
    cout << string(80, '=') << endl;
    cout << left << setw(15) << "Data Size"
         << setw(20) << "Insert (μs)"
         << setw(20) << "ExtractMin (μs)"
         << setw(20) << "Total (μs)" << endl;
    cout << string(80, '-') << endl;
    
    for (const auto& result : results) {
        cout << left << setw(15) << result.dataSize
             << setw(20) << fixed << setprecision(2) << result.insertTime
             << setw(20) << result.extractMinTime
             << setw(20) << result.totalTime << endl;
    }
    cout << string(80, '=') << endl;
}

void exportToCSV(const vector<TestResult>& results, const string& filename) {
    ofstream file(filename);
    file << "DataSize,InsertTime,ExtractMinTime,TotalTime\n";
    
    for (const auto& result : results) {
        file << result.dataSize << ","
             << result.insertTime << ","
             << result.extractMinTime << ","
             << result.totalTime << "\n";
    }
    
    file.close();
    cout << "\nResults exported to " << filename << endl;
}

int main() {
    cout << "Binary Heap Performance Test" << endl;
    cout << "Testing insertion and extraction operations\n" << endl;
    
    vector<int> testSizes = {1000, 5000, 10000, 20000, 50000};
    vector<TestResult> allResults;
    
    for (int size : testSizes) {
        cout << "Testing with " << size << " elements... ";
        cout.flush();
        
        auto result = testBinaryHeap(size);
        allResults.push_back(result);
        
        cout << "Done (" << result.totalTime / 1000.0 << " ms)" << endl;
    }
    
    printResults(allResults);

    exportToCSV(allResults, "performance_results.csv");
    
    cout << "\nPerformance test completed successfully!" << endl;
    
    return 0;
}
