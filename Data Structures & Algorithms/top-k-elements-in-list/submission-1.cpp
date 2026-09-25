class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> table;
        for(int i  : nums){
            table[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for(const auto& k : table){
            pq.push({k.second,k.first});
        }
        vector<int> res;
        while(k>0){ 
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
        
    }
};
