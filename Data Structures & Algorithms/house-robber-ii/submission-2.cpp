class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        return max(helper(vector<int>(nums.begin()+1,nums.end())), helper(vector<int> (nums.begin(), nums.end()-1)));
    }


    int helper(vector<int> a){
      int n = a.size();
      if(n==0) return 0;
      if(n==1) return a[0];

      vector<int> dp(n);
      dp[0] = a[0];
      dp[1] = max(a[0], a[1]);

      for(int i = 2; i<a.size();i++){
        dp[i] = max(a[i]+dp[i-2], dp[i-1]);

      }
      return dp[n-1];

    }


};
