import java.util.Arrays;
import java.util.Scanner;

public class BinarySearchExample {
    public static int binarySearch(char[] arr, char key) {
        int left = 0;
        int right = arr.length - 1;

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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the size of the sorted array from the user
        System.out.print("Enter the size of the sorted array: ");
        int size = scanner.nextInt();

        // Create an array of the specified size
        char[] arr = new char[size];

        // Get the elements of the sorted array from the user
        System.out.print("Enter " + size + " elements of the sorted array (in ascending order): ");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.next().charAt(0);
        }

        // Get the character to search for from the user
        System.out.print("Enter the character to search for: ");
        char key = scanner.next().charAt(0);

        // Perform binary search and get the result
        Arrays.sort(arr); // Binary search requires the array to be sorted
        int position = binarySearch(arr, key);

        // Display the result
        if (position != -1) {
            System.out.println("'" + key + "' found at position " + (position + 1) + ".");
        } else {
            System.out.println("'" + key + "' not found in the array.");
        }

        scanner.close();
    }
}
