
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Linear Search Algorithm
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search Algorithm
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Merge Sort Algorithm
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    // Linear Search
    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1)
        cout << "Linear Search: Target found at index " << linearResult << endl;
    else
        cout << "Linear Search: Target not found." << endl;

    // Binary Search
    sort(arr, arr + n); // Binary search requires a sorted array
    int binaryResult = binarySearch(arr, 0, n - 1, target);
    if (binaryResult != -1)
        cout << "Binary Search: Target found at index " << binaryResult << endl;
    else
        cout << "Binary Search: Target not found." << endl;

    // Bubble Sort
    bubbleSort(arr, n);
    cout << "Sorted Array using Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Merge Sort
    vector<int> mergeArr(arr, arr + n);
    mergeSort(mergeArr, 0, n - 1);
    cout << "Sorted Array using Merge Sort: ";
    for (int i = 0; i < n; i++) {
        cout << mergeArr[i] << " ";
    }
    cout << endl;

    return 0;
}