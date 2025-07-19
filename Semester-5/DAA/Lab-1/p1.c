// Factorial of a number using recursion and iteration in C.

//Iterative:-

// #include <stdio.h>
// void main(){
//     int n, fact=1;
//     scanf("%d",&n);
//     for(int i=n;i>=1;i--){
//         fact=fact*i;
//     }
//     printf("Factorial is: %d ",fact);
// }

//Recusive:-

#include <stdio.h>
int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*fact(n-1);
}
void main(){
    int n;
    scanf("%d",&n);
    int ans=fact(n);
    printf("Factorial is : %d",ans);
}
