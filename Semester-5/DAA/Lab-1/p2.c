// Program to find the sum of first n natural numbers using recursion and iteration.

//Iterative:- 

// #include <stdio.h>
// void main(){
//     int n,ans;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         ans = ans + i;
//     }
//     printf("Sum of n is: %d",ans);
// }

//Recursive:-

#include <stdio.h>
int sum(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n+sum(n-1);
}
void main(){
    int n;
    scanf("%d",&n);
    int ans=sum(n);
    printf("Sum of n is : %d",ans);
}