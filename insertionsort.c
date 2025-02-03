#include<stdio.h>
#include<stdlib.h>

void insertionsort(int *a, int n) {
    int i, j, v;
    int opcount = 0;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (++opcount && j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = v;
    }
    printf("\nOperation count: %d\n", opcount);
}

int main() {
    int *a;
    int i, j, k, n = 5;
    for (j = 0; j < 4; j++) {
        a = (int *)malloc(sizeof(int) * n);
        for (k = 0; k < n; k++) {
            a[k] = n - k;
        }
        printf("Elements are: ");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        insertionsort(a, n);
        printf("Elements after sorting: ");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        free(a);
        n = n + 5;
    }
    return 0;
}
