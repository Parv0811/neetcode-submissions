class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length();
        int b = s2.length();
        int c = s3.length();

        vector<vector<bool>> dp(a+1, vector<bool> (b+1,false));
        dp[a][b] = true;
        if(a+b!=c){
            return false;
        }
    
        for(int i = a; i>=0 ; i--){
            for(int j = b; j>=0 ;j--){
                if(i<a && s1[i] == s3[i+j]){
                    if(dp[i+1][j]) {dp[i][j] = true;}
                }
                if(j<b && s2[j] == s3[i+j]){
                    if (dp[i][j+1]){dp[i][j] = true;}
                }
            }
        }

        return dp[0][0];

        
    }
};
