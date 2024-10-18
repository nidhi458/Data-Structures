#include <stdio.h>
#define MAX 100

void insert(int value, int stack1[], int *top1) {
    if (*top1 == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        stack1[++(*top1)] = value;
        printf("inserted %d\n", value);
    }
}

int delete(int stack1[], int *top1, int stack2[], int *top2) {
    if (*top1 == -1 && *top2 == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    if (*top2 == -1) {
        while (*top1 != -1) {
            stack2[++(*top2)] = stack1[(*top1)--];
        }
    }
    
    int value = stack2[(*top2)--];
    printf("deleted element: %d\n", value);
    return value;
}

int main() {
    int stack1[MAX], stack2[MAX];
    int top1 = -1, top2 = -1;
    int choice, value;
    
    while (1) {
        printf("\nQueue using Stacks Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                insert(value, stack1, &top1);
                break;
            case 2:
                delete(stack1, &top1, stack2, &top2);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
