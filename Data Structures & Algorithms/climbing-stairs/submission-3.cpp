class Solution {
    
public:
    vector<int> cache;
    int climbStairs(int n) {
        cache.resize(n,-1);
        return dfs(n,0);
    }

    int dfs(int n, int curr){
        if(curr>=n) return curr==n;
        if(cache[curr]!=-1) return cache[curr];

        return cache[curr] = dfs(n,curr+1)+dfs(n,curr+2);
    }
};
