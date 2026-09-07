class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);

        LIS[n-1] = 1;

        for(int i = n-2; i>=0 ; i--){
            for(int j = i+1; j<n; j++){
                if(nums[i]<nums[j]){
                    LIS[i] = max(1+LIS[j],LIS[i]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());


        
    }
};
