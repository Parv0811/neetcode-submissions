class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 0;
        suffix[n-1] = 0;

        for(int i = 1;i<n;i++){
            prefix[i] = max(prefix[i-1],height[i-1]);
            suffix[n-i-1] = max(suffix[n-i],height[n-i]);
        }

        int sum = 0;
        for(int i = 0;i<n;i++){
            int val = min(prefix[i],suffix[i]) - height[i];
            if(val<=0)continue;
            else{
                sum+=val;
            }
        }
        return sum;

        
    }
};
