class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid = (l+r/2);

        while(l<=r){
            int mid = (l) + (r-l)/2;
            if(nums[r]>nums[mid]){
               r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return nums[l-1];
    }
};
