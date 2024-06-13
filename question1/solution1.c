#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//author: Frank Onyema Orji

void printLCSubStr(char* X, char* Y, int m, int n)
{
    int LCSuff[m+1][n+1];
    int len = 0;
    int row, col;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                if (len < LCSuff[i][j])
                {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            }
            else LCSuff[i][j] = 0;
        }
    }

    if (len == 0)
    {
        printf("No Common Substring");
        return;
    }

    char* resultStr = (char*) malloc((len + 1) * sizeof(char));

    while (LCSuff[row][col] != 0)
    {
        resultStr[--len] = X[row - 1];
        row--;
        col--;
    }

    printf("Longest Common Substring: %s\n", resultStr);
}

int main()
{
    char X[] = "Similar";
    char Y[] = "Small";
    int m = strlen(X);
    int n = strlen(Y);

    printLCSubStr(X, Y, m, n);
    return 0;
}
