// Program to find power of a number using iterative and recursive method

//Iterative:-

// #include <stdio.h>
// void main(){
//     int a,b,ans =1;
//     scanf ("%d",&a);
//     scanf("%d",&b);
//     for(int i=1;i<=b;i++){
//         ans=ans*a;
//     }
//     printf("%d",ans);
// }

//Recursive:-
#include <stdio.h>
int power(int a,int b){
    if(b==0 || b==1){
        return a;
    }
    return a*power(a,b-1);
}
void main(){
    int a,b,ans=1;
    scanf("%d",&a);
    scanf("%d",&b);
    ans=power(a,b);
    printf("Power is : %d",ans);
}
