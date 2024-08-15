#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define N 100

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

int operation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;
    else if (op == '^')
        return (int)pow(a, b);
    else
        return 0;
}

int evaluate(const char * expression)
{
    int l = strlen(expression);
    int result = 0;
    char operator_stack[l];
    int operand_stack[l];
    int operator_top = -1;
    int operand_top = -1;
    for (int i = 0; i < l; i++)
    {
        if (expression[i] == ' ')
        continue;

        if (isdigit(expression[i]))
        {
            int temp = 0;
            while (i < l && isdigit(expression[i]))
            {
                temp = temp * 10 + (expression[i] - '0');
                i++;
            }
            operand_stack[++operand_top] = temp;
            i--;
        }
        else if (isOperator(expression[i]))
        {
            while (operator_top >= 0 && precedence(operator_stack[operator_top]) >= precedence(expression[i]))
            {
            int b = operand_stack[operand_top--];
            int a = operand_stack[operand_top--];
            operand_stack[++operand_top] = operation(a, b, operator_stack[operator_top--]);
            }
            operator_stack[++operator_top] = expression[i];
        }   
    }
    while (operator_top >= 0)
    {
        int b = operand_stack[operand_top--];
        int a = operand_stack[operand_top--];
        operand_stack[++operand_top] = operation(a, b, operator_stack[operator_top--]);
    }
    result = operand_stack[operand_top];
    return result;
}

int main()
{
    char expression[N];
    printf("enter the infix expressoin (without brackets and spaces): ");
    scanf("%s", expression);
    int result = evaluate(expression);
    printf("The result is %d", result);
    return 0;
}