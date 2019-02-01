#include <stdio.h>

void merge_sort(int *arr, int *aux, int start, int length) {
    if (length == 1) {
        return;
    }

    // divide
    int m = (int) length / 2;

    // conquer sub-problems
    merge_sort(arr, aux, start, m);
    merge_sort(arr, aux, start + m, length - m);

    // combine (merge)
    int l = start;
    int r = start + m;

    int i = start;

    while (l < start + m && r < start + length) {
        if (arr[l] < arr[r]) {
            aux[i] = arr[l++];
        } else {
            aux[i] = arr[r++];
        }

        i++;
    }

    while (l < start + m) {
        aux[i++] = arr[l++];
    }

    while (r < start + length) {
        aux[i++] = arr[r++];
    }

    for (int j = start; j < start + length; ++j) {
        arr[j] = aux[j];
    }

    return;
}

int main(void) {
    int length = 5;

    int arr[5] = { 5, 3, 4, 2, 1 };
    int aux[5] = { 0 };

    merge_sort(arr, aux, 0, length);

    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
