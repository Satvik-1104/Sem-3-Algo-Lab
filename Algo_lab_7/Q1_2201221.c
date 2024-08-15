#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fact (char s[200], int n)
{
    if (n > 1)
    {
        char a[200];
        snprintf(a, sizeof(a), "%d", n - 1);
        int i1 = strlen(s);
        int i2 = strlen(a);
        int * result = malloc((i1 + i2) * sizeof(int));
        memset(result, 0, (i1 + i2) * sizeof(int));

        for (int i = i1 - 1; i >= 0; i--)
        {
            for (int j = i2 - 1; j >= 0; j--)
            {
                int mul = (s[i] - '0') * (a[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        char *resultstr = (char *)malloc((i1 + i2 + 1) * sizeof(char));
        int index = 0;
        while (index < i1 + i2 && result[index] == 0)
        index++;
        if (index == i1 + i2)
        {
            strcpy(resultstr, "0");
        }
        else
        {
            for (int i = index; i < i1 + i2; i++)
            {
                resultstr[i - index] = result[i] + '0';
            }
            resultstr[i1 + i2 - index] = '\0';
        }
        free (result);
        strcpy (s, resultstr);
        free (resultstr);
        fact (s, n - 1);
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    char str[200];
    snprintf(str, sizeof(str), "%d", n);
    fact(str, n);
    printf("The result outcome is %s.\n", str);
    return 0;
}