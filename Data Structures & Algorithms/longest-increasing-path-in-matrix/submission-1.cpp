class Solution {
    vector<vector<int>> directions  = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> dp;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size(), LIP = 0;
        dp = vector<vector<int>> (ROWS, vector<int> (COLS,-1));
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                LIP = max(LIP, dfs(matrix, r, c, INT_MIN));
            }
        }
        return LIP;
    }


    int dfs(vector<vector<int>>& matrix, int r, int c, int preVal){
        if(r<0 || r ==matrix.size() || c<0 || c==matrix[0].size() || matrix[r][c]<=preVal){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }

        int res = 1;
        for(const auto& d : directions){
            res = max(1+dfs(matrix,r+d[0],c+d[1],matrix[r][c]), res);
        }
        dp[r][c] = res;
        return res;
    }
};
