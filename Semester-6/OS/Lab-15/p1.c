// Write a C Program to implement:1. FIFO Page Replacement algorithm

#include <stdio.h>

int main()
{
    int pages[50], frame[10];
    int n, f, i, j, k, flag, faults = 0, index = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frame[i] = -1;

    for(i=0;i<n;i++)
    {
        flag = 0;

        for(j=0;j<f;j++)
        {
            if(frame[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            frame[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }

        printf("\nFrames: ");
        for(k=0;k<f;k++)
            printf("%d ", frame[k]);
    }

    printf("\nTotal Page Faults = %d", faults);
}