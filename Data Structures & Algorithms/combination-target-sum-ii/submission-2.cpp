class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        dfs(0, target, ans, nums);

        return res;
    }

    void dfs(int i, int target, vector<int>& ans, vector<int>& nums) {
        if(target == 0) {
            res.push_back(ans);
            return;
        }
        if(i==nums.size()) return;

        if(nums[i]<=target){
            ans.push_back(nums[i]);
            dfs(i+1,target-nums[i],ans,nums);
            ans.pop_back();
        }

        while(i<nums.size()-1 && nums[i]==nums[i+1]){
            i++;
        }
        dfs(i+1,target,ans,nums);

        

    }
};