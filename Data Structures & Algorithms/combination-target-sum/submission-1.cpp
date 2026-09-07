class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        int sum = 0;
        dfs(nums,subset,sum,target,0);

        return res;
        
    }
private:
    void dfs(const vector<int> & nums, vector<int>& subset, int sum, const int target,int i){
        if(sum==target){
            res.push_back(subset);
            return;
        }
        else if(sum>target || i>=nums.size()){
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,subset,sum+nums[i],target,i);
        subset.pop_back();
        dfs(nums,subset,sum,target,i+1);
        
    }

};
