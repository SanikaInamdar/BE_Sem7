#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function to partition the array
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Deterministic Quick Sort
void deterministicQuickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        deterministicQuickSort(arr, low, pivot - 1);
        deterministicQuickSort(arr, pivot + 1, high);
    }
}

// Randomized Quick Sort
int randomPartition(std::vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

// Function to print an array
void printArray(const std::vector<int> &arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    std::cout << "Original Array: ";
    printArray(arr);

    // Sorting using Deterministic Quick Sort
    deterministicQuickSort(arr, 0, n - 1);
    std::cout << "Array sorted using Deterministic Quick Sort: ";
    printArray(arr);

    // Resetting the array
    arr = {12, 11, 13, 5, 6};

    // Setting the random seed for the randomized version
    std::srand(std::time(0));

    // Sorting using Randomized Quick Sort
    randomizedQuickSort(arr, 0, n - 1);
    std::cout << "Array sorted using Randomized Quick Sort: ";
    printArray(arr);

    return 0;
}
