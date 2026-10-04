class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()){
            return false;
        }
        unordered_map<int,int> stab;
        unordered_map<int,int> ttab;

        for(int i = 0;i<s.size();i++){
            stab[s[i]-'a']++;
            ttab[t[i]-'a']++;
        }

        return (stab==ttab) ;
        
    }
};
