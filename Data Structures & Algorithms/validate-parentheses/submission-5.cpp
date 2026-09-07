class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Closing brackets
            else {

                // No opening bracket to match
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                // Matching pair
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    st.pop();
                }

                // Doesn't match
                else {
                    return false;
                }
            }
        }

        // Stack should be empty if all brackets matched
        return st.empty();
    }
};
