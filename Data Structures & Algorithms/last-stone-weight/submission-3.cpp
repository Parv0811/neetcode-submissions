class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }

        while(pq.size()>1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(abs(a-b)>0){
                pq.push(abs(a-b));
            }
            else continue;
        }
        return (!pq.empty()) ? pq.top() : 0;
    }
};
