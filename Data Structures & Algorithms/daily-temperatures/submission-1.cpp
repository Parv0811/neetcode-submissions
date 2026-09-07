class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <pair<int,int>> st;
        vector <int> res(temperatures.size(),0);
        
        for(int i=0;i<temperatures.size();i++){
            int k = 0;
            while(!st.empty() && st.top().first<temperatures[i]){
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }
            st.push({temperatures[i],i});
        }
        return res;
        
    }
};
