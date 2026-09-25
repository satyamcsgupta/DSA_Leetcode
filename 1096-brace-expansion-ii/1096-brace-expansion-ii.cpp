class Solution {
public:

    set<string> solve(string &s, int &i) {

        set<string> result;
        set<string> current;

        current.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++; // skip {

                set<string> inside = solve(s, i);

                i++; // skip }

                // Concatenate current × inside
                set<string> temp;

                for (string a : current) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;

            }
            else if (s[i] == ',') {

                // Union current into result
                for (string x : current) {
                    result.insert(x);
                }

                current.clear();
                current.insert("");

                i++;
            }
            else {

                // Normal character
                string ch(1, s[i]);

                set<string> temp;

                for (string x : current) {
                    temp.insert(x + ch);
                }

                current = temp;

                i++;
            }
        }

        // Add last part
        for (string x : current) {
            result.insert(x);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};