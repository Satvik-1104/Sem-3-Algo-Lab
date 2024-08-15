#include <stdio.h>

void findSubsequence (int a[], int n, int d)
{
    int s[n];
    int l = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[j] - a[i]) >= d)
            {
                l++;
                s[index++] = a[i];
                i = j;
                if (j == n - 1)
                {
                    l++;
                    s[index++] = a[j];
                }
            }
        }
    }
    printf("The length of the sequence is %d\n", l);
    printf("The sequence is: ");
    for (int i = 0; i < index; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main ()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    int d;
    printf ("Enter d: ");
    scanf("%d", &d);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a[i]);
    }
    printf ("The given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    findSubsequence(a, n, d);
    return 0;
}