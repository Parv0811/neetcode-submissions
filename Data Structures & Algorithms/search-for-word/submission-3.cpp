class Solution {
public:
        int ROWS;
        int COL;
        set<pair<int,int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COL = board[0].size();

        for(int i = 0;i<ROWS;i++){
            for(int j = 0;j<COL;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
                
            }
        }
        return false;  
    }
    bool dfs(vector<vector<char>> board, string word, int r, int c, int i ){
        if(i==word.size()){
            return true;
        }
        if(r < 0 || c < 0 ||r >= ROWS || c >= COL || path.count({r,c}) || board[r][c]!= word[i] ){
            return false;
        }

        path.insert({r,c});
        bool res = dfs(board, word, r+1, c, i+1) || dfs(board, word, r, c+1, i+1) || dfs(board, word, r-1, c, i+1) || dfs(board, word, r, c-1, i+1);
        path.erase({r,c});
        return res;
    }
};
