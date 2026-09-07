class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        vector<vector<int>> res;
        for(auto& point : points){
            maxHeap.push({point[0]*point[0] + point[1]*point[1],{point[0],point[1]}});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty()){
            res.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
        
    }
};
