class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minBuy = prices[0];
        for(const auto& sell  : prices){
            maxP = max(maxP, sell - minBuy);
            minBuy  = min(minBuy,sell); 
        }
        return maxP;
        
    }
};
