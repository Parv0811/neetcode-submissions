class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> count(26, 0);

        for(char c : tasks) {
            count[c - 'A']++;
        }

        priority_queue<int> pq;

        for(int cnt : count) {
            if(cnt > 0)
                pq.push(cnt);
        }

        queue<pair<int,int>> q;
        // {remaining count, time when it becomes available}

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            // Release tasks whose cooldown is over
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()) {

                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0) {
                    q.push({cnt, time + n + 1});
                }
            }
        }

        return time;
    }
};