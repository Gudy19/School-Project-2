// School Project
// Name: Obadiah Goodnews Chukwu

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>  // for setprecision
using namespace std;

// Bubble Sort (XXXXX Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i -1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Merge helper and Merge Sort (YYYYY Sort)
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

vector<int> generateRandomArray(int size) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

void measureSortingTimeFirstSortingAlgorithm(vector<int>& arr, double& timeExecuted, double& timeComplexity) {
    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();
    timeExecuted = double(end - start) / CLOCKS_PER_SEC;
    timeComplexity = arr.size() * arr.size();
}

void measureSortingTimeSecondSortingAlgorithm(vector<int>& arr, double& timeExecuted, double& timeComplexity) {
    clock_t start = clock();
    mergeSort(arr, 0, arr.size() - 1);
    clock_t end = clock();
    timeExecuted = double(end - start) / CLOCKS_PER_SEC;
    timeComplexity = arr.size() * log2(arr.size());
}

int main() {
    cout << "COS2611 Assessment 2 Project 1 - Skeleton \n";
    cout << "ARRAYS\n\n";

    vector<int> inputSizes = {100, 1000, 5000};

    cout << fixed << setprecision(3); // 3 decimal places for times

    for (int size : inputSizes) {
        vector<int> arr = generateRandomArray(size);
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;

        double timeExecuted1, timeExecuted2, timeComplexity1, timeComplexity2;

        measureSortingTimeFirstSortingAlgorithm(arr1, timeExecuted1, timeComplexity1);
        measureSortingTimeSecondSortingAlgorithm(arr2, timeExecuted2, timeComplexity2);

        cout << "Input Size: " << size << "\n\n";

        cout << "XXXXX Sort:\n";
        cout << "Execution Time: " << timeExecuted1 << " seconds\n\n";

        cout << "YYYYY Sort:\n";
        cout << "Execution Time: " << timeExecuted2 << " seconds\n\n";
    }

    cout << "The time complexity formula for XXXXX: O(n^2)\n";
    cout << "The time complexity formula for YYYYY: O(n log n)\n";

    return 0;
}
