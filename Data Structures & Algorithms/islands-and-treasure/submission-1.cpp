class Solution {
public:
    queue<pair<int, int>> q;

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Put all treasure cells into the queue
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // BFS
        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            addRoom(r + 1, c, grid, r, c);
            addRoom(r - 1, c, grid, r, c);
            addRoom(r, c + 1, grid, r, c);
            addRoom(r, c - 1, grid, r, c);
        }
    }

private:

    void addRoom(int r, int c, vector<vector<int>>& grid,
                 int prevR, int prevC) {

        // Outside grid or not an unvisited empty room
        if (r < 0 || c < 0 ||
            r >= grid.size() || c >= grid[0].size() ||
            grid[r][c] != INT_MAX) {
            return;
        }

        // Distance = previous cell's distance + 1
        grid[r][c] = grid[prevR][prevC] + 1;

        // Add to queue
        q.push({r, c});
    }
};