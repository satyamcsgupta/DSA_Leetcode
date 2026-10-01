class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push('(');
            }
            else if (s[i] == '[') {
                st.push('[');
            }
            else if (s[i] == '{') {
                st.push('{');
            }
            else {
                if (st.empty()) {
                    return false;
                }

                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};