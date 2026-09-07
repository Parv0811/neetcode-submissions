class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size()-1;
        int l = 0;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>=nums[r]){
                l = m + 1;
            }
            else{
                r = m; 
            }
        }
        int pivot = l;

        int a  = binarySearch(nums, 0, pivot-1,target);
        if (a!= -1){
            return a;
        }
        else{
            return binarySearch(nums,pivot,nums.size()-1,target);
        }

        
    }
    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left<=right){
            int mid = (left + right)/2;

            if(nums[mid]>target){
                right = mid - 1;
            }
            else if(nums[mid]<target){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;

    }
};
