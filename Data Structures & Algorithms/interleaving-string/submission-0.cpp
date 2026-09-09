class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int m = s1.size();
        int n = s2.size();

        if(m + n != s3.size())
            return false;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // If both strings are finished, we successfully formed s3
        dp[m][n] = 1;

        // i = position in s1
        // j = position in s2
        for(int i = m; i >= 0; i--) {
            for(int j = n; j >= 0; j--) {

                if(i == m && j == n)
                    continue;

                int k = i + j;

                // Take character from s1
                if(i < m && s1[i] == s3[k]) {
                    dp[i][j] = dp[i + 1][j];
                }

                // Take character from s2
                if(j < n && s2[j] == s3[k]) {
                    dp[i][j] = dp[i][j] || dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};