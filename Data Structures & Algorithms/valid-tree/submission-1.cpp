class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visit;
        vector<vector<int>> adj(n);
        if(edges.size()>n-1){
            return false;
        }

        for(const auto& ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        if(!dfs(0,-1,adj,visit)){
            return false;
        }
        return visit.size()==n;

    }
private:
    bool dfs(int curr, int prev, vector<vector<int>>& adj,  unordered_set<int>& visit){
        if(visit.count(curr)){
            return false;
        }
        visit.insert(curr);
        for(int nei : adj[curr]){
            if(nei==prev){
                continue;
            }
            if(!dfs(nei,curr,adj,visit)){
                return false;
            }
        }
        return true;
    }

};
