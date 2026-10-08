class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n,-1);
        vector<int> dp(n,0);

        return dfs(n,0,nums);
        // dp[0] = nums[0];
        // dp[1] = max(nums[1],dp[0]);
    }
    int dfs(int n, int i, vector<int>& nums){
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];

        return memo[i] = max(nums[i]+dfs(n,i+2,nums),dfs(n,i+1,nums));


    }
};
