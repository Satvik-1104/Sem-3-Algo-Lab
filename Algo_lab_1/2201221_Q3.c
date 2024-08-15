#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length (char n_str[501])
{
    return strlen(n_str);
}

void multiply(char n1_str[501], char n2_str[501], int n1, int n2)
{
    int n1_dig[501] = {0}; 
    int n2_dig[501] = {0}; 
    for (int i = n1 - 1, j = 0; i >= 0, j < n1; i--, j++)
    {
        n1_dig[j] = n1_str[i] - '0';
    }
    for (int i = n2 - 1, j = 0; i >= 0, j < n2; i--, j++)
    {
        n2_dig[j] = n2_str[i] - '0';
    }
    int product[1002] = {0};
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            product[i + j] = product[i + j] + n1_dig[i] * n2_dig[j];
            product[i + j + 1] = product[i + j + 1] + product[i + j] / 10;
            product[i + j] = product[i + j] % 10;
        }
    }
    int p = n1 + n2;
    while (product[p - 1] == 0 && p > 0)
    {
        p--;
    }  
    printf("The product is: ");
    for (int i = p - 1; i >= 0; i--)
    {
        printf("%d", product[i]);
    }
}

int main()
{
    char n1_str[501];
    char n2_str[501];
    printf("enter the numbers: ");
    scanf("%s %s", n1_str, n2_str);
    int n1 = length(n1_str);
    int n2 = length(n2_str);
    printf("%d %d\n", n1, n2);
    multiply(n1_str, n2_str, n1, n2);
}