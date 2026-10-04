class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for(int i = 0;i<nums.size();i++){
            count[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for(const auto& c : count){
            pq.push({c.second,c.first});
        }
        vector<int> res;
        int i = 1;
        while(i<=k){
            auto curr  = pq.top();
            pq.pop();
            res.push_back(curr.second);
            i++;
        }
        return res;
        
    }
};
