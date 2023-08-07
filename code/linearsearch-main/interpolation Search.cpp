#include <iostream>

int interpolationSearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right && key >= arr[left] && key <= arr[right]) {
        if (left == right) {
            if (arr[left] == key)
                return left;
            return -1;
        }

        int pos = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == key)
            return pos;
        else if (arr[pos] < key)
            left = pos + 1;
        else
            right = pos - 1;
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

    // Perform interpolation search and get the result
    int position = interpolationSearch(arr, size, key);

    // Display the result
    if (position != -1) {
        std::cout << key << " found at position " << position + 1 << "." << std::endl;
    } else {
        std::cout << key << " not found in the array." << std::endl;
    }

    return 0;
}
