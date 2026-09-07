class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int i = 0;
        int total = 0;
        vector<int> curr;
        dfs(candidates,i,total,curr,target);
        return res;

    }

private:
    void dfs(vector<int>& candidates,int i, int total, vector<int>& curr,const int target){
        if(target==total){
            res.push_back(curr);
            return;
        }
        if(total>target || i>=candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        dfs(candidates,i+1,total + candidates[i],curr,target);

        curr.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
            i++;
        }
        dfs(candidates,i+1,total,curr,target);
    }
};
