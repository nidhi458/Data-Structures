#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;
void push(int value)
{
    if(top==MAX-1)
    {
        printf("stack is overflow, cannot push %d onto the stack\n",value);
    }
    else
    {
        top++;
        stack[top]=value;
        printf("the value of %d has been pushed onto the stack \n", value);
    }
}
int pop()
{
    if (top==-1)
    {
        printf("stack underflow. Cannot pop from an empty stack\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}
void display()
{
    if (top==-1)
    {
        printf("stack is empty\n");

    }
    else
    {
        for (int i = top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(){
    int value,op;
    do{
        printf("\n 1.push");
        printf("\n 2.pop");
        printf("\n 3.display");
        printf("\n 4.exit");

        printf("\n enter the first option");
        scanf("%d",&op);
        switch(option)
        {
            case 1:
            printf("\n enter the number to be pushed on stack:");
            scanf("%d",&value);
            push(value);
            break;

            case 2:
            value = pop();
            if(value!=-1){
            printf("\n the value deleted from stack is: %d",value);
            }

            case 3:
            display();
            break;

            case 4:
            printf("exiting the program\n");
            break;
        }
    }
    while(op!=4);
    return 0;
}