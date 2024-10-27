#include <iostream>

int BinarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;  // Correct way to set the upper bound
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;  // Return -1 if target is not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the correct size
    std::cout << BinarySearch(arr, size, 4) << std::endl;
    return 0;
}
