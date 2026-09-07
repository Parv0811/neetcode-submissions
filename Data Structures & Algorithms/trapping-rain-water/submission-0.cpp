class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int l=0;
        int r=height.size()-1;
        int hl_Max=height[l];
        int hr_Max=height[r];
        int res=0;
        while(l<r){
            if(hl_Max<hr_Max){
                l++;
                hl_Max=max(hl_Max,height[l]);
                res+=hl_Max-height[l];
            }
            else {
                r--;
                hr_Max=max(hr_Max,height[r]);
                res+=hr_Max-height[r];
            }
        }
        return res;
        
    }
};
