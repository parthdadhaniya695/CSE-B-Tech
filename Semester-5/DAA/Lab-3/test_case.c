#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;

    fp = fopen("best.txt","w");
    for(int i=0;i<100000;i++){
        fprintf(fp, "%d ",i);
    }
    fclose(fp);

    fp = fopen("worst.txt","w");
    for(int i=100000;i>0;i--){
        fprintf(fp, "%d ",i);
    }
    fclose(fp);

    fp = fopen("average.txt","w");
    for(int i=0;i<100000;i++){
        fprintf(fp, "%d ",rand());
    }
    fclose(fp);
    return 0;
}