#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *partition(int *left, int *right) {
    int pivot = *(left + (right - left) / 2);
    int *low = left;
    int *high = right;
    while (1) {
        while (*(low) < pivot) {
            low++;
        }
        while (*(high) > pivot) {
            high--;
        }
        if (high <= low) {
            return high;
        }
        swap(low++, high--);
    }

}

void quicksort(int *left, int *right) {
    if (left < right) {
        int *p = partition(left, right);
        quicksort(left, p);
        quicksort(p + 1, right);
    }
}

int main() {
    int n = 100;
    int *a = (int *) malloc(sizeof(int) * n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
    quicksort(a, a + n - 1);
    for (int i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }


    return 0;
}


