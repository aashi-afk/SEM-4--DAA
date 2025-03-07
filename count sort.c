#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int findMax(int array[], int n) {
    int max = array[0];
    int i;
    for ( i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to perform counting sort
void countingSort(int array[], int n) {
    // Find the maximum value in the array
    int max = findMax(array, n);

    // Create a count array to store the count of each element
    int* count = (int*) calloc(max + 1, sizeof(int));

    // Store the count of each element
    int i;
    for (i = 0; i < n; i++) {
        count[array[i]]++;
    }

    // Update the count array
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    int* output = (int*) malloc(n * sizeof(int));

    // Build the output array
    for ( i = n - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (i = 0; i < n; i++) {
        array[i] = output[i];
    }

    // Free the dynamically allocated memory
    free(count);
    free(output);
}

// Utility function to print array elements
void printArray(int array[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// Driver code to test the counting sort implementation
int main() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array is \n");
    printArray(array, n);

    countingSort(array, n);

    printf("Sorted array is \n");
    printArray(array, n);

    return 0;
}
