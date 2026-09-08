class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        if(total - target < 0 || (total - target) % 2 != 0)
            return 0;

        int sum = (total - target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int t = 0; t <= sum; t++) {

                // Don't take nums[i]
                dp[i][t] = dp[i + 1][t];

                // Take nums[i]
                if(t >= nums[i]) {
                    dp[i][t] += dp[i + 1][t - nums[i]];
                }
            }
        }

        return dp[0][sum];
    }
};