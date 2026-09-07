class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int longest=0;

        for(int n : nums){
            if(!numSet.count(n-1)){
                int length=0;
                while(numSet.count(length+n)){
                    length++;
                }
                longest=max(longest,length);
            }
        }
        return longest;

        
    }
};
