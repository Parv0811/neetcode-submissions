class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int c= a+b;
                num.push(c);
            }
            else if(tokens[i]=="*"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int c= a*b;
                num.push(c);
            }
            else if(tokens[i]=="-"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int c= b-a;
                num.push(c);
            }
            else if(tokens[i]=="/"){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int c= b/a;
                num.push(c);
            }
            else num.push(stoi(tokens[i]));
        }
        return num.top();

        
    }
};
