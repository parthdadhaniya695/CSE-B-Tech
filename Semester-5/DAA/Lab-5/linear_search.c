#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000 

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    FILE *file1;
    clock_t start, end;
    double cpu_time_used;
    int arr[SIZE], n;

    file1 = fopen("../Lab-3/best.txt", "r");
    if (file1 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fscanf(file1, "%d", &arr[i]);
    }
    fclose(file1);

    printf("Which number do you want to find? ");
    scanf("%d", &n);

    start = clock();
    
    int index = linearSearch(arr, SIZE, n);

    end = clock();

    cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element is not in the array\n");
    }

    printf("Time used: %lf microseconds\n", cpu_time_used);

    return 0;
}
