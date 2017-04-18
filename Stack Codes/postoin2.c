#include <stdio.h>
  #include <string.h>

  #define BUFSIZE 100

  char operator[] = {'/', '*', '+', '-', '%', '$'};
  char stack[BUFSIZE][BUFSIZE];
  int top = -1;

  /* push input string into the stack */
  void push(char *substr) {
        char *temp;
        if (top >= BUFSIZE -1) {
                printf("Stack Overflow\n");
        } else {
                top++;
                strcpy(stack[top], substr);
        }
        return;
  }

  /* pop top element from the stack & append input string with top element */
  void pop(char *res) {
        if (top == -1) {
                printf("Stack Underflow\n");
                return;
        } else {
                strcpy(res, stack[top]);
                top--;
        }
        return;
  }

  int main() {
        char expr[BUFSIZE], buffer1[BUFSIZE], buffer2[BUFSIZE];
        int i, j, len, flag = 0;
        printf("Enter your postfix expression:");
        fgets(expr, 100, stdin);
        expr[strlen(expr) - 1] = '\0';

        for (i = 0; expr[i] != '\0'; i++) {
                if (expr[i] == ' ')
                        continue;

                for (j = 0; j < 6; j++) {
                        if (expr[i] == operator[j]) {
                                flag = 1;
                                break;
                        }
                }
                /*
                 * scanned character is operator, pop two
                 * elements from stack, form a string composed
                 * of scanned character and the two popped
                 * element from the stack
                 */
                if (flag) {
                        pop(buffer1);
                        pop(buffer2);
                        len = strlen(buffer2);
                        buffer2[len++] = expr[i];
                        buffer2[len] = '\0';
                        strcat(buffer2, buffer1);
                        push(buffer2);
                } else {
                        /* scanned input is digit, push it into the stack */
                        buffer1[0] = expr[i];
                        buffer1[1] = '\0';
                        push(buffer1);
                }
                flag = 0;
        }
        printf("Postfix to Infix Conversion:\n");
        printf("Posfix: %s\n", expr);
        printf("Infix: ");
        for (i = 0; i <= top; i++) {
                printf("%s",stack[i]);
        }
        printf("\n\n");
        return 0;
  }