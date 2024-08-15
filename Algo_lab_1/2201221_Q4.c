#include <stdio.h>

int main()
{
    int n;
    int arg;
    printf("enter n: ");
    scanf("%d", &n);
    char m[n][n];
    printf("the input matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = '*';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
    int s = 0;
    int l = 1;
    printf("enter the argument: ");
    scanf("%d", &arg);
    while (l < n)
    {
        int k = 0;
        while (k < arg)
        {
            for (int i = 0; i < n; i++)
            {
                m[l][i] = ' ';
            }
            if (s % 2 == 0)
            {
                m[l][n - 1] = '*';
            }
            else
            {
                m[l][0] = '*';
            }
            l++;
            k++;
        }
        s++;
        l++;
    }
    printf("the modified matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}