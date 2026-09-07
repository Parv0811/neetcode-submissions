class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int,int>> pair;
        for(int i=0; i<position.size();i++){
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());
        stack <double> st;
        
        st.push((double)(target-pair[0].first)/pair[0].second);

        for(int i = 1;i<position.size();i++){
            double t = ((double)(target - pair[i].first))/(double)(pair[i].second);
            if(t<=st.top()){
                continue;
            }
            st.push(t);
            
        }
        return st.size();

        
    }
};
