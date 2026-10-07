class Solution {
public:

    vector<string> ans;

    void remove(string& s, int start, int last,
                char open, char close) {

        int balance = 0;

        for (int i = start; i < s.size(); i++) {

            if (s[i] == open)
                balance++;

            else if (s[i] == close)
                balance--;

            // We found an invalid prefix
            if (balance < 0) {

                for (int j = last; j <= i; j++) {

                    // Only remove the first ')' among consecutive ')'
                    if (s[j] == close &&
                        (j == last || s[j - 1] != close)) {

                        string temp = s;

                        temp.erase(j, 1);

                        remove(temp, i, j, open, close);
                    }
                }

                return;
            }
        }

        // No invalid ')' found.
        // Now check the opposite direction.
        reverse(s.begin(), s.end());

        if (open == '(') {

            remove(s, 0, 0, ')', '(');

        } else {

            // Valid answer
            ans.push_back(s);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        remove(s, 0, 0, '(', ')');

        return ans;
    }
};