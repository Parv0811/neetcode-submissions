class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        dfs(0,target,ans,nums);
        return res;
        
    }

    void dfs(int index, int target,vector<int>& ans, vector<int>& nums){
        if(target==0 ){
            res.push_back(ans);
            return;
        }
        if(index==nums.size()) return;
        if(nums[index]<=target){
            ans.push_back(nums[index]);
            dfs(index, target - nums[index], ans, nums);
            ans.pop_back();
        }

        dfs(index+1,target,ans,nums);
        
    }
};
