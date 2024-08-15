#include <stdio.h>

void sortGroupsofThree (int g3, int gofThree[3][g3])
{
    for (int i = 0; i < g3; i++)
    {
        
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int g3 = (n + 2) / 3;
    int g5 = (n + 4) / 5;
    int g7 = (n + 6) / 7;
    
    int gofThree[3][g3];
    int gofFive[5][g5];
    int gofSeven[7][g7];

    int i = 0, j = 0;

    for (i = 0; i < g3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((i * 3 + j) < n)
            gofThree[j][i] = a[i * 3 + j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < g3; j++)
        {
            if ((j * 3 + i) < n)
            printf("%d ", gofThree[i][j]);
        }
        printf("\n");
    }

    sortGroupsofThree (g3, gofThree);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < g3; j++)
        {
            if ((j * 3 + i) < n)
            printf("%d ", gofThree[i][j]);
        }
        printf("\n");
    }

    return 0;
}