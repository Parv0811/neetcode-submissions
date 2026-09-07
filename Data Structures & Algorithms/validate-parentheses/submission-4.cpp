class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty, no matching opening bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check if the current closing bracket matches the top of stack
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Stack should be empty if all brackets matched
        return st.empty();
    }
};
