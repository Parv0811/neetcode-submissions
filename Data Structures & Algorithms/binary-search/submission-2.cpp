class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        int mid = (left+right)/2;

        while(left<right){
            if(target<nums[left] || target>nums[right]){
            return -1;
            }
            if(target == nums[mid]){
                return mid;
            }
            if(nums[mid]> target){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
            mid = (left + right)/2;
            
        }

        
    }
};
