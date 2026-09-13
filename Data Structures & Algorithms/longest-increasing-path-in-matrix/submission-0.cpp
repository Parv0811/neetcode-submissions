class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c, int preVal){
        if(r<0 || r==matrix.size() || c<0 || c==matrix[0].size() || matrix[r][c]<=preVal){
            return 0;
        }

        if(dp[r][c]!= -1){
            return dp[r][c];
        }

        int res = 1;
        for(const auto& d : directions){
            res = max(res, 1 + dfs(matrix, r + d[0], c + d[1], matrix[r][c]));
        }
        dp[r][c] = res;
        return res;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        dp = vector<vector<int>> (n, vector<int> (m,-1));

        int LIP = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0;j<m;j++){
               LIP = max(LIP,dfs(matrix,i,j,INT_MIN)); 
            }
        }
        return LIP;

        
        
    }
};
