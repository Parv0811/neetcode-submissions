class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> store;
        for (const auto &i : nums){
            store[i]++;
        }
        priority_queue <pair<int,int>> pq;
        for (const auto &k : store){
            pq.push({k.second, k.first});
        }
        vector <int> res;
        int t=0;
        while(k>0){
            res.push_back(pq.top().second);
            pq.pop();
            t++;
            k--;
        }
        return res;
    }
};
