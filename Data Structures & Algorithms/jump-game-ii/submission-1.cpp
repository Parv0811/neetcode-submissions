class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 2000);
        dp[n-1] = 0;

        for(int i = n-2;i>=0;i--){
            int end = min(n-1, i + nums[i]);

            for(int j = i+1;j<=end;j++){
                dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp[0];

        
    }
};
