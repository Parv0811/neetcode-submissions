class Solution {
public:
    unordered_set<int> visiting;
    unordered_map<int, vector<int>> preMap;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0;i<numCourses;i++){
            preMap[i] = {};
        }
        for(const auto& prereq : prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for(int  c = 0 ; c< numCourses ; c++){
            if(!dfs(c)){
                return false;
            }

        }
        return true;
    }
private: 
    bool dfs(int c){
        if(visiting.count(c)){
            return false;
        }
        if(preMap[c].empty()){
            return true;
        }
        visiting.insert(c);
        for(int pre : preMap[c]){
            if(!dfs(pre)){
                return false;
            }
        }
        visiting.erase(c);
        preMap[c].clear();
        return true;
    }
};
