class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> table;
        for(int i = 0;i<s.length();i++){
            table[s[i]] = i;
        }
        int size = 0;
        int end = 0;
        vector<int> res;
        for(int i = 0;i<s.length();i++){
            size++;
            end = max(end,table[s[i]]);
            if(i==end){
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};
