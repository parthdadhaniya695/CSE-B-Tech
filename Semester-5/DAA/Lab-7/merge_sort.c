#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    FILE *fp;
    clock_t start, end;
    double cputime;
    int arr[100000], n, choice;
    char filename[50];

    printf("Select the case to sort:\n");
    printf("1. Best Case\n");
    printf("2. Average Case\n");
    printf("3. Worst Case\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    printf("Enter Number Of Elements: ");    
    scanf("%d", &n);

    switch (choice) {
        case 1:
            sprintf(filename, "../Lab-3/best.txt");
            break;
        case 2:
            sprintf(filename, "../Lab-3/average.txt");
            break;
        case 3:
            sprintf(filename, "../Lab-3/worst.txt");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("Original array:\n");
    printArray(arr, n);

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC; 

    printf("Sorted array:\n");
    printArray(arr, n);

    printf("Time Taken = %f seconds\n", cputime);

    return 0;
}
