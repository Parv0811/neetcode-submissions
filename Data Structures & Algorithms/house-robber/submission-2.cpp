class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n);
        t[0] = nums[0];
        if(n==1){
            return t[0];
        }
        t[1] = max(nums[1],t[0]);

        for(int i=2; i<n ; i++){
            t[i] = max(t[i-1],t[i-2]+ nums[i]);
        }
        
        return t[n-1];
        
    }
};
