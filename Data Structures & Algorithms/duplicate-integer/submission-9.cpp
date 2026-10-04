class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_map<int,int> table;

        for(int i  = 0;i<nums.size();i++){
            table[nums[i]]++;
            if(table[nums[i]]>1){
                return true;
            }
        }

        return false;
    }
};