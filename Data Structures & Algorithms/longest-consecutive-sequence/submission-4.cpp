class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int con=1;
        int max_con=con;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]){
                continue;
            }
            else if(nums[i+1]-nums[i]==1){
                con++;
                max_con=max(max_con,con);
            }
            else{
                con=1;
            }
        }
        return max_con;
        
    }
};
