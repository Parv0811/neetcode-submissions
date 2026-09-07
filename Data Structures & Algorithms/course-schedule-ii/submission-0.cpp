class Solution {
    
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preReq;
        unordered_set<int> visited;
        unordered_set<int> cycle;
        vector<int> output;
        for(const auto& pair  : prerequisites){
            preReq[pair[0]].push_back(pair[1]);
        }
        for(int course = 0 ; course<numCourses; course++){
            if(!dfs(course,preReq,visited,cycle,output)){
                return {};
            }
        }
        return output;
    }
    
    bool dfs(int course, unordered_map<int, vector<int>>& preReq, unordered_set<int>& visited, unordered_set<int>& cycle , vector<int>& output){
        if(cycle.count(course)){
            return false;
        }
        if(visited.count(course)){
            return true;
        }
        cycle.insert(course);
        if(preReq.count(course)){
            for(int pre : preReq.at(course)){
                if(!dfs(pre, preReq, visited, cycle, output)){
                    return false;
                }
            }
        }
        cycle.erase(course);
        visited.insert(course);
        output.push_back(course);
        return true;
    }
};
