#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//author: Frank Onyema Orji

// Function to find the longest common subsequence
char* longestCommonSubsequence(char* Text1, char* Text2) {
    int m = strlen(Text1);
    int n = strlen(Text2);
    int dp[m+1][n+1];

    // Initialize the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (Text1[i-1] == Text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    // Reconstruct the LCS
    int index = dp[m][n];
    char* lcs = (char*)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (Text1[i-1] == Text2[j-1]) {
            lcs[--index] = Text1[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    char Text1[] = "Similar";
    char Text2[] = "Small";

    char* result = longestCommonSubsequence(Text1, Text2);
    printf("Longest Common Subsequence: %s\n", result);

    free(result);
    return 0;
}
