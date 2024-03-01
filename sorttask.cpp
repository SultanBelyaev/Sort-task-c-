#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

/*QuickSort */

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
int randomPartition(std::vector<T>& arr, int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(low, high);
    int randomIndex = dis(gen);
    std::swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };

    std::cout << "ishodniy:" << std::endl;
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sort:" << std::endl;
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}



////////////////////////////////////////////
/*bubble Sort */

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int randomPivot(std::vector<T>& arr, int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(low, high);
    return dis(gen);
}

int main() {
    std::vector<int> arr = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };

    std::cout << "ishodniy:" << std::endl;
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "sort:" << std::endl;
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}



///////////////////////////////////////////////////////////
/*countingSort */


template <typename T>
int randomPivot(const std::vector<T>& count, int low, int high);

template <typename T>
void countingSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = randomPivot(arr, low, high);
        std::swap(arr[pivotIdx], arr[high]);

        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        int partitionIdx = i + 1;

        countingSort(arr, low, partitionIdx - 1);
        countingSort(arr, partitionIdx + 1, high);
    }
}

template <typename T>
int randomPivot(const std::vector<T>& count, int low, int high) {
    return low + rand() % (high - low + 1);
}

int main() {
    std::vector<int> arr = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 6 };
    int n = arr.size();

    countingSort(arr, 0, n - 1);

    std::cout << "Sort: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}