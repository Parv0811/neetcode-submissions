class Solution {
public:
    void backtrack(int openN,int closedN, int n, vector<string>& res, string& stack){
        if(openN==closedN && openN==n){
            res.push_back(stack);
            return;
        }
        if(openN<n){
            stack +='(';
            backtrack(openN+1,closedN,n,res,stack);
            stack.pop_back();
        }
        if(openN>closedN){
            stack +=')';
            backtrack(openN,closedN+1,n,res,stack);
            stack.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int openN=0;
        int closedN=0;
        vector<string> res;
        string stack;
        backtrack(openN,closedN,n,res,stack);
        return res;
        
    }
};
