#include <stdio.h>

int bruteForce (int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    else
        return bruteForce (n - 1) + bruteForce (n - 2);
}

int topDown (int n, int a[])
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    if (a[n] != -1)
    {
        return a[n];
    }
    a[n] = topDown(n - 1, a) + topDown(n - 2, a);
    return a[n];
}

int bottomUp (int n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

int bottomUpConst (int n)
{
    int a[3];
    a[0] = 0;
    a[1] = 1;
    for (int i = n - 1; i > 0; i--)
    {
        a[2] = a[0] + a[1];
        a[0] = a[1];
        a[1] = a[2];
    }
    return a[2];
}

int main()
{
    int n;
    printf("Enter the number to find the Fibonacci of: ");
    scanf("%d", &n);

    int brute_force = bruteForce (n);
    printf("f(%d) = %d (by brute force)\n", n, brute_force);

    int s = n + 1;
    int a[s];
    for (int i = 0; i < s; i++)
    {
        a[i] = -1;
    }
    int top_down = topDown (n, a);
    printf("f(%d) = %d (by top down)\n", n, top_down);

    int bottom_up = bottomUp (n);
    printf("f(%d) = %d (by bottom up)\n", n,  bottom_up);

    int bottom_up_const_space = bottomUpConst (n);
    printf("f(%d) = %d (by bottom up with constant space complexity)\n", n,  bottom_up_const_space);
}