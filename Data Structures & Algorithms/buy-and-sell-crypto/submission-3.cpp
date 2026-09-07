class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prefix(prices.size());
        prefix[0] = INT_MAX;

        for(int i = 1;i<prices.size();i++){
            prefix[i] = min (prefix[i-1],prices[i-1]);
        }
        int profit  = 0;
        for(int j=0;j<prices.size();j++){
            if (prices[j]-prefix[j]>0){
                profit = max(prices[j]-prefix[j],profit);
            }
        }
        return profit;
        
    }
};
