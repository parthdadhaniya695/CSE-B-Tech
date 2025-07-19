# include<stdio.h>
# include<stdlib.h>
# include<time.h>

int main(){

    FILE *fp;
    clock_t start,end;
    double cputime;
    int a[100000];
    int n,i,j,temp,choice;
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
            sprintf(filename, "best.txt");
            break;
        case 2:
            sprintf(filename, "average.txt");
            break;
        case 3:
            sprintf(filename, "worst.txt");
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

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);

    start = clock();

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    end = clock();
    cputime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    printf("Time Taken = %f seconds\n", cputime);

    return 0;
}
