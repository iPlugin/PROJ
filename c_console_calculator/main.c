#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

double evaluateExpression(const char *expr) {
    double result = 0.0;
    double num = 0.0;
    char op = '+';
    char *p = (char *)expr;

    while (*p) {
        if (isdigit(*p)) {
            num = strtod(p, &p);
            switch (op) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    if (num != 0) {
                        result /= num;
                    } else {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
            }
        } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            op = *p++;
        } else {
            p++;
        }
    }

    return result;
}

int main() {
    char expression[MAX_EXPR_LEN];
    double result;

    printf("Enter an arithmetic expression (e.g., 3+5*2-8/4): ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = '\0';

    result = evaluateExpression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
