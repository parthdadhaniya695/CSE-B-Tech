//stack using push,pop,peep,change,display 
#include <stdio.h>
#include <stdlib.h>

#define size 100
int stack[size],top=-1;

void push(int value){
    if(top>=size-1){
        printf("Stack is overflow\n");
    }
    else{
        stack[++top]=value;
        printf("pushed %d\n",value);
    }
}
void pop(){
    if(top<=1){
        printf("Stack is underflow\n");
    }
    else{
        printf("popped %d\n",stack[top--]);
    }
}
void peep(){
    if(top<=-1){
        printf("Stack is empty\n");
    }
    else{
        printf("top element is %d\n",stack[top]);
    }
}
void change(int position,int value){
    if(top-position+1<=-1 || position<=0){
        printf("Invalid position\n");
    }
    else{
        stack[top-position+1]=value;
        printf(" value changed at position %d\n",position);
    }
}
void display(){
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}
void main(){
    int choice,value,position;
    while(1){
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peep\n");
        printf("4.change\n");
        printf("5.display\n");
        printf("6.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter value\n");
            scanf("%d",&value);
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            peep();
            break;

            case 4:
            printf("enter position\n");
            scanf("%d",&position);
            printf("enter value\n");
            scanf("%d",&value);
            change(position,value);
            break;

            case 5:
            display();
            break;

            default:
            printf("invalid choice\n");
        }
    }
}