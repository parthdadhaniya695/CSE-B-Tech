# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void selectionsort(int arr[],int length){
    int i,j,minIndex, temp;
    for(i=0;i<length;i++){
        minIndex = i;
        for(j=i+1;j<length;j++){
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i]=temp;
    }
}

int main(){
    FILE *fp;
    clock_t start,end;
    double cputime;
    int a[100000],n,choice;
    char filename[20];

    printf("Select the case to sort:\n");
    printf("1. Best Case\n");
    printf("2. Average Case\n");
    printf("3. Worst Case\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    printf("Enter Number Of Elements:");    
    scanf("%d",&n);

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
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);

    start = clock();

    selectionsort(a,n);

    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    printf("Time Taken = %f seconds\n", cputime);

    return 0;

}