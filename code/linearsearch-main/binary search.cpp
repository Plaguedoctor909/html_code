#include <iostream>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // If the element is not found, return -1
}

int main() {
    int size, key;

    // Get the size of the sorted array from the user
    std::cout << "Enter the size of the sorted array: ";
    std::cin >> size;

    // Create an array of the specified size
    int arr[size];

    // Get the elements of the sorted array from the user
    std::cout << "Enter " << size << " elements of the sorted array (in ascending order): ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Get the number to search for from the user
    std::cout << "Enter the number to search for: ";
    std::cin >> key;

    // Perform binary search and get the result
    int position = binarySearch(arr, 0, size - 1, key);

    // Display the result
    if (position != -1) {
        std::cout << key << " found at position " << position + 1 << "." << std::endl;
    } else {
        std::cout << key << " not found in the array." << std::endl;
    }

    return 0;
}
