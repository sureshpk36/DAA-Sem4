#include <stdio.h>
#include <string.h>

// Function to find the length of LCS
int lcs(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[100][100]; // assuming max length of strings is less than 100

    // Fill the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // base case
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // match
            } else {
                // no match, take max of top or left cell
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m][n]; // length of LCS
}

int main() {
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    int length = lcs(str1, str2);
    printf("Length of Longest Common Subsequence is: %d\n", length);

    return 0;
}
