class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_k = *max_element(piles.begin(),piles.end());
        int min_k = 1;
        
        int k = (max_k + min_k)/2;
        int res = max_k;
        while(max_k>=min_k){
            int t = 0;
            for (int i = 0;i<piles.size();i++){
                t += ceil((double)(piles[i]) / k);
            }
            if(t<=h){
                res = k;
                max_k = k - 1;
            }
            else{
                min_k = k + 1;
            }
            
            k = (max_k + min_k)/2;

        }
        return res;
        
    }
};
