class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,vector<int>>,vector<pair<float,vector<int>>>,greater<pair<float,vector<int>>>> pq;
        for(auto point  : points){
            pq.push({point[0]*point[0] + point[1]*point[1],{point[0],point[1]}});
        }
        vector<vector<int>> res;
        while(k>0){
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
            k--;
        }
        return res;
    }
};
