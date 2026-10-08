class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> maps;
        unordered_map<string, bool> dp;

        int maxs = 0;
        int mins = INT_MAX;

        for(auto k : wordDict) {
            maps[k] = k.size();

            maxs = max(maxs, (int)k.size());
            mins = min(mins, (int)k.size());
        }

        return dfs(s, maps, mins, maxs, dp);
    }

    bool dfs(string s,
             unordered_map<string, int>& maps,
             int mins,
             int maxs,
             unordered_map<string, bool>& dp) {

        if(s.empty()) {
            return true;
        }

        // Already solved this string
        if(dp.count(s)) {
            return dp[s];
        }

        for(int i = mins; i <= maxs; i++) {

            if(s.size() >= i) {

                string p = s.substr(0, i);

                if(maps.count(p)) {

                    if(dfs(s.substr(i), maps, mins, maxs, dp)) {
                        return dp[s] = true;
                    }
                }
            }
        }

        return dp[s] = false;
    }
};