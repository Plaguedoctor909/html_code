#include <iostream>
#include <cmath>

int jumpSearch(int arr[], int size, int key) {
    int jump = static_cast<int>(sqrt(size));
    int prev = 0;

    while (arr[std::min(jump, size) - 1] < key) {
        prev = jump;
        jump += sqrt(size);
        if (prev >= size)
            return -1;
    }

    for (int i = prev; i < std::min(jump, size); i++) {
        if (arr[i] == key) {
            return i;
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

    // Perform jump search and get the result
    int position = jumpSearch(arr, size, key);

    // Display the result
    if (position != -1) {
        std::cout << key << " found at position " << position + 1 << "." << std::endl;
    } else {
        std::cout << key << " not found in the array." << std::endl;
    }

    return 0;
}
