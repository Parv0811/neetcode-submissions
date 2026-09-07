class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxleft(height.size());
        vector<int> maxright(height.size());
        int n=height.size()-1;
        int maxl=height[0];
        for(int i=0;i<height.size();i++){
            maxl = max(height[i],maxl);
            maxleft[i]=maxl;
        }
        int maxr=height[n];    
        for(int i=n;i>=0;i--){
            maxr = max(height[i],maxr);
            maxright[i]=maxr;
        }   
        vector<int> minLR(height.size()); 
        for(int i=0;i<height.size();i++){
            minLR[i] = min(maxright[i],maxleft[i]);
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            sum = sum + (minLR[i]-height[i]);
        }
        return sum;
    }
        
    
};
