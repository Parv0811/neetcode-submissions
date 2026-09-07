class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> str_s;
        unordered_map<char,int> str_t;

        for(int i=0; i<s.length();i++){
            str_s[s[i]]++;
            str_t[t[i]]++;
        }
        return str_s == str_t;
    }
};
