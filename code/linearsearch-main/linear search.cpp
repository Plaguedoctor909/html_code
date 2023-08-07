#include <iostream>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // If the element is not found, return -1
}

int main() {
    int size, key;

    // Get the size of the array from the user
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Create an array of the specified size
    int arr[size];

    // Get the elements of the array from the user
    std::cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Get the number to search for from the user
    std::cout << "Enter the number to search for: ";
    std::cin >> key;

    // Perform linear search and get the result
    int position = linearSearch(arr, size, key);

    // Display the result
    if (position != -1) {
        std::cout << key << " found at position " << position + 1 << "." << std::endl;
    } else {
        std::cout << key << " not found in the array." << std::endl;
    }

    return 0;
}
