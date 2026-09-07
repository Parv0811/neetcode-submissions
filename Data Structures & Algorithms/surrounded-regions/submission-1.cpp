class Solution {
    vector<pair<int,int>> directions  = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        for(int r = 0; r<ROWS;++r){
            for(int c = 0;c <COLS;++c){
                if(board[r][c]=='O' && (r==0 || r==ROWS-1 || c ==0 || c==COLS-1 )){
                    capture(r,c,board);
                }
            }
        }

        for(int r = 0;r<ROWS;++r){
            for(int c = 0 ;c<COLS;++c){
                if(board[r][c]=='T'){
                    board[r][c]='O';
                }
                else{
                    board[r][c]='X';
                }
            }
        }
        
        
    }

private:

    void capture(int r, int c, vector<vector<char>> & board){
        if (r<0 || c<0 ||r>=board.size() || c>=board[0].size() || board[r][c] != 'O'){
            return;
        }
        board[r][c]='T';
        for(auto& [dr,dc] : directions){
            int nr = r + dr;
            int nc = c + dc;
            capture(nr,nc,board);
        }
    }
};
