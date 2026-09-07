class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());

        prefix[0] = 0;
        suffix[height.size()-1] = 0;

        for(int i=1; i<height.size();i++){
            prefix[i] = max (prefix[i-1],height[i-1]);
            suffix[height.size()-1-i]= max(suffix[height.size()-i],height[height.size()-i]);
        }
        int area_trapped  = 0;
        for(int i = 0;i<height.size();i++){
            if (min(prefix[i],suffix[i])-height[i]>=0){
                area_trapped += min(prefix[i],suffix[i])-height[i];
            }
        }
        return area_trapped;
        
    }
};
