class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int num:stones){
            maxHeap.push(num);
        }

        while(maxHeap.size()>1){
            int a  = maxHeap.top();
            maxHeap.pop();
            int b  = maxHeap.top();
            maxHeap.pop();
            if(a-b>0){
                maxHeap.push(a-b);
            }
        }
        return (!maxHeap.empty()) ? maxHeap.top() : 0;

        
    }
};
