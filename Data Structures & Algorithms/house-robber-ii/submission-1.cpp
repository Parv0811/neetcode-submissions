class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(n==1){
        return nums[0];
      } 
      if(n==2){
        return max(nums[0],nums[1]);
      }
      vector<int> t(n-1); 
      t[0] = nums[0];
      t[1] = max(nums[1],t[0]);
      for(int i=2;i<n-1;i++){
        t[i] = max(t[i-2]+nums[i],t[i-1]);
      }
      vector<int> p(n-1);
      p[0] = nums[1];
      p[1] = max(nums[2],p[0]);
      for(int i=2;i<n-1;i++){
        p[i] = max(nums[i+1]+p[i-2],p[i-1]);
      }

      return(max(t[n-2],p[n-2]));
        
    }
};
