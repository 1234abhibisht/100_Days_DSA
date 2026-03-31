#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Top pointer
struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;
    
    while (exp[i] != '\0') {

        // If operand, push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');   // Convert char to int
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;

                default:
                    printf("Invalid Operator\n");
                    exit(1);
            }
        }
        i++;
    }

    return pop();
}

// Main function
int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
