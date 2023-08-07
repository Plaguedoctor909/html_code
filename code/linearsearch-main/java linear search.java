import java.util.Scanner;

public class LinearSearchExample {
    public static int linearSearch(char[] arr, char key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1; // If the element is not found, return -1
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the size of the array from the user
        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        // Create an array of the specified size
        char[] arr = new char[size];

        // Get the elements of the array from the user
        System.out.print("Enter " + size + " elements of the array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.next().charAt(0);
        }

        // Get the character to search for from the user
        System.out.print("Enter the character to search for: ");
        char key = scanner.next().charAt(0);

        // Perform linear search and get the result
        int position = linearSearch(arr, key);

        // Display the result
        if (position != -1) {
            System.out.println("'" + key + "' found at position " + (position + 1) + ".");
        } else {
            System.out.println("'" + key + "' not found in the array.");
        }

        scanner.close();
    }
}
