class Solution {
public:
    bool isPalindrome(string s) {
        string p;
        for( auto & c:s){
            if(isalnum(c)){
                c=tolower(c);
                p=p+c;
            }
        }
        cout<<p;
        string rev=p;
        reverse(rev.begin(),rev.end());
        return p==rev;
    }
};
