class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r= nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            // check for left portions of the array
            if(nums[mid]>=nums[l]){
                if(target>nums[mid] || target<nums[l]) {
                    l=mid+1;
                }
                else if(nums[mid]>target && target>=nums[l]){
                    r=mid-1;
                } 
            }
            // right sorted 
            else {
                if(target<nums[mid] || target>nums[r]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }

                }
            }
            return -1;
        }
    };

