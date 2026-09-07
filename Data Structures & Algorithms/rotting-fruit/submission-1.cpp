class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time  = 0;
        int fresh = 0;

        for(int r = 0;r<grid.size();r++){
            for(int c = 0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    fresh++;
                }
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }

        vector<pair<int,int>> directions  = {{1,0},{0,1},{0,-1},{-1,0}};

        while(!q.empty() && fresh>0){
            int length = q.size();
            for(int i = 0; i<length;i++){
                auto curr  = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(const auto& dir : directions){
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]==1){
                        q.push({row,col});
                        fresh--;
                        grid[row][col]=2;
                    }
                }
            }
            time++;

        }
        if(fresh){
            return -1;
        }
        return time;
        
    }
};
