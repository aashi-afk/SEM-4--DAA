#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r) {
    int i = l-1;
    int x = a[r];
    for (int j=l;j<r;j++) {
        if (a[j]<=x) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    i++;
    swap(&a[i],&a[r]);
    return i;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int q = partition(a,l,r);
        for (int i = 0; i < r; i++)
        {
        printf("%d ", a[i]);
        }
        printf("\n");
        quicksort(a,l,q - 1);
        quicksort(a,q + 1,r);
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

    quicksort(a, 0, n - 1);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
