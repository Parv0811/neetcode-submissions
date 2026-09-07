class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1){
            return false;
        }
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }

        if(sum%2!=0){
            return false;
        }
        int target  = sum/2;
        unordered_set<int> tab;
        tab.insert(0);
        tab.insert(nums[n-1]);

        for(int i = n-2;i>=0;i--){
            unordered_set<int> old = tab;
            for(int x : old){
                tab.insert(x+nums[i]);
                if(tab.count(target)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
