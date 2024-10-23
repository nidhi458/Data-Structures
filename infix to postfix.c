#include <stdio.h>
#define MAX 100

void push(char stack[], int *top, char c) {
    if (*top < MAX - 1) {
        stack[++(*top)] = c;
    }
}

char pop(char stack[], int *top) {
    if (*top >= 0) {
        return stack[(*top)--];
    } else {
        return '\0';
    }
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

int isOperand(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

void infixtopostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    char token;

    while ((token = infix[i]) != '\0') {
        if (isOperand(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(stack, &top, token);
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top); 
        } else { 
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, token);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixtopostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
