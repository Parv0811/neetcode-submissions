class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<bool> visit(n, false);
        int res  = 0;
        for(int node = 0; node<n; node++){
            if(!visit[node]){
                bfs(node, visit, adj);
                res++;
            }
        }
        return res;

    }
private:
    void bfs(int node, vector<bool>& visit, vector<vector<int>>& adj){
        queue<int>q;
        q.push(node);
        visit[node] = true;
        while(!q.empty()){
            int curr  = q.front();
            q.pop();
            for(int nei : adj[curr]){
                if(!visit[nei]){
                    visit[nei]=true;
                    q.push(nei);
                }
            }
        }
    }
};
