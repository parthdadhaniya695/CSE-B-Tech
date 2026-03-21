// Write a C Program to implement:1. Optimal Page Replacement algorithm

#include <stdio.h>

int main()
{
    int pages[50], frame[10];
    int n, f, i, j, k, flag, pos, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d",&n);

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
            int farthest = i, index = -1;

            for(j=0;j<f;j++)
            {
                int found = 0;

                for(k=i+1;k<n;k++)
                {
                    if(frame[j] == pages[k])
                    {
                        if(k > farthest)
                        {
                            farthest = k;
                            index = j;
                        }
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    index = j;
                    break;
                }
            }

            if(index == -1)
                index = 0;

            frame[index] = pages[i];
            faults++;
        }

        printf("\nFrames: ");
        for(j=0;j<f;j++)
            printf("%d ",frame[j]);
    }

    printf("\nTotal Page Faults = %d",faults);
}