#include <stdio.h>

int min_height(int n)
{
    int count = 0;
    int temp = n;
    while (temp != 0)
    {
        count++;
        temp = temp / 2;
    }
    return count - 1;
}

int max_height(int n)
{  
    int prev = 0;
    int cur = 1;
    int lat = 2;
    int count = 0;
    while (n >= lat)
    {
        int temp = cur;
        cur = lat;
        prev = temp;
        lat = prev + cur + 1;
        count++;
    }
    return count;
}

int main()
{
    int n;
    printf("enter the no.of nodes: ");
    scanf("%d", &n);
    int min = min_height(n);
    printf("the minimum height of the AVL tree of %d nodes is %d\n",n, min);
    int max = max_height(n);
    printf("the maximum height of the AVL tree of %d nodes is %d", n, max);
}