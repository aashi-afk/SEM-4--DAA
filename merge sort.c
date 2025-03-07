#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergeSort(int a[], int l, int r, int size) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m, size);
        mergeSort(a, m + 1, r, size);
        merge(a, l, m, r);
        printArray(a, size);  // Print the array after each merge
    }
}

int main() {
    int a[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    int n = sizeof(a) / sizeof(a[0]);

    printf("oringinal elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergeSort(a, 0, n - 1, n);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
