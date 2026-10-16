class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum  = 0;
        int sum  = 0;
        if(nums.size()==1) return nums[0];
        int neg_max = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=0){
                neg_max = max(neg_max,nums[i]);
            }
            sum +=nums[i];
            if(sum<0){
                sum = 0;
                continue;
            }
            maxSum = max(sum,maxSum);
        }
        return (maxSum>0) ? maxSum : neg_max;

    }
};
