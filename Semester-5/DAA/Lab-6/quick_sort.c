#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);      

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void createBestCase(int arr[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    swap(&arr[mid], &arr[high]);

    createBestCase(arr, low, mid - 1);
    createBestCase(arr, mid + 1, high);
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

            for (int i = 0; i < n; i++)
                arr[i] = i + 1;

            createBestCase(arr, 0, n - 1);

            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Unable to create best.txt\n");
                return 1;
            }
            for (int i = 0; i < n; i++) {
                fprintf(fp, "%d\n", arr[i]);
            }
            fclose(fp);
            break;

        case 2: 
            sprintf(filename, "../Lab-3/average.txt");

            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Unable to create average.txt\n");
                return 1;
            }

            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                int num = rand() % 100000;
                fprintf(fp, "%d\n", num);
            }
            fclose(fp);
            break;

        case 3: 
            sprintf(filename, "../Lab-3/worst.txt");

            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Unable to create worst.txt\n");
                return 1;
            }
            for (int i = 0; i < n; i++) {
                fprintf(fp, "%d\n", i + 1);
            }
            fclose(fp);
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

    printf("Original array: \n");
    printArray(arr, n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC; 

    printf("Sorted array: \n");
    printArray(arr, n);

    printf("Time Taken = %f seconds\n", cputime);

    return 0;
}
