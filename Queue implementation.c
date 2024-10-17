#include<stdio.h>
#define MAX 10


void insert(int val, int *rear, int *front, int queue[]) {
    if (*rear == MAX - 1) {
        printf("The queue is full\n");
    } else {
        if (*front == -1 && *rear == -1) {
            *front = *rear = 0;
        } else {
            *rear = *rear + 1;
        }
        queue[*rear] = val;
        printf("%d inserted into the queue\n", val);
    }
}


void delete(int *front, int *rear, int queue[]) {
    if (*front == -1 || *front > *rear) {
        printf("The queue is empty\n");
    } else {
        int val = queue[*front];
        printf("%d deleted from the queue\n", val);
        *front = *front + 1;
        if (*front > *rear) {
            *front = *rear = -1;  
        }
    }
}


void display(int *rear, int *front, int queue[]) {
    if (*front == -1) {
        printf("The queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = *front; i <= *rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int option = 0, val;
    int queue[MAX];
    int front = -1, rear = -1;

    while (option != 4) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(val, &rear, &front, queue);
                break;
            case 2:
                delete(&front, &rear, queue);
                break;
            case 3:
                display(&rear, &front, queue);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
