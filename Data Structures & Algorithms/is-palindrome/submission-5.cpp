#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char c : s){
            if(isalnum(c)){
                t += tolower(c);
            }
        }
        for(int i = 0; i <t.size();i++){
            if (t[i] != t[t.size()-1-i]){
                return false;
            }
        }
        return true;

        
    }
};
