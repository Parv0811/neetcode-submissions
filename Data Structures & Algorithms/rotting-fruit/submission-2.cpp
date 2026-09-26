class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> queue;
        vector<vector<int>> directions = {{1,0},{0,1},{0,-1},{-1,0}};
        int fresh = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    queue.push({i,j});
                }
            }
        }
        int time = 0;
        while(!queue.empty() && fresh>0){
            int length = queue.size();
            for(int i = 0;i<length;i++){
                auto curr  = queue.front();
                queue.pop();
                for(const auto& d : directions){
                    int r = curr.first + d[0];
                    int c = curr.second + d[1];
                    if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]==1){
                        grid[r][c]=2;
                        queue.push({r,c});
                        fresh--;
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
