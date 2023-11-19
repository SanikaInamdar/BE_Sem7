#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        while (j >= i && arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

// Deterministic QuickSort
void deterministicQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        deterministicQuickSort(arr, low, pivotIndex - 1);
        deterministicQuickSort(arr, pivotIndex + 1, high);
    }
}

// Randomized QuickSort
void randomizedQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Randomly choose pivot and swap with the first element
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[low], arr[randomIndex]);

        int pivotIndex = partition(arr, low, high);

        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Example usage
    vector<int> arr = {12, 4, -12, 5, 6, 7, 3, -8, 1, 15};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Applying Deterministic QuickSort
    deterministicQuickSort(arr, 0, arr.size() - 1);
    cout << "Array after deterministic QuickSort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Re-initialize the array
    arr = {12, 4, -12, 5, 6, 7, 3, -8, 1, 15};

    // Applying Randomized QuickSort
    randomizedQuickSort(arr, 0, arr.size() - 1);
    cout << "Array after randomized QuickSort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Best Case Time Complexity: O(n log n)
// Average Case Time Complexity: O(n log n)
// Worst Case Time Complexity: O(n^2) (with a low probability due to the randomized variant)
// Space Complexity: O(1) +  O(log n) -> recursive stack