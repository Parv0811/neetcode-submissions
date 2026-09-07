class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,{},nums);
        return res;
    }
private:    
    void backtrack(int i, vector<int> subset, vector<int>& nums){
        if(i==nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(i+1,subset,nums);
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        subset.pop_back();
        backtrack(i+1,subset,nums);
    }
};
