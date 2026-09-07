class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool>pick(nums.size(),false);

        dfs(subset,nums,pick);
        return res;
    }

    void dfs(vector<int>& subset,vector<int>& nums,vector<bool>& pick){
        if(subset.size()==nums.size()){
            res.push_back(subset);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!pick[i]){
                subset.push_back(nums[i]);
                pick[i] = true;
                dfs(subset,nums,pick);
                subset.pop_back();
                pick[i]=false;
            }
        }

    }
};
