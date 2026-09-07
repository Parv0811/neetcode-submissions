class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMax = 1;
        int currMin = 1;

        for(int n : nums){
            int temp = n*currMax;
            currMax = max({n*currMax,n*currMin,n});
            currMin = min({temp,n*currMin,n});

            res = max(res,currMax);
        }
        return res;
        
    }
};
