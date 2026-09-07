class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> indices;
        for(int i=0;i<numbers.size();i++){
            indices[numbers[i]]=i;
        }

        for(int i=0;i<numbers.size();i++){
            int diff = target-numbers[i];
            if(indices.count(diff) && indices[diff]!=i){
                return {i+1, indices[diff]+1};
            }
        }

        
    }
};
