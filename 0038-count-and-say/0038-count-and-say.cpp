class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";
        int index = 1;

        while (index < n) {

            string next = "";
            int count = 0;
            int sz = ans.size();
            int i = 0;

            char prev = ans[0];

            while (i < sz) {

                if (prev == ans[i]) {
                    count++;
                }
                else {
                    next += to_string(count);
                    next += prev;

                    prev = ans[i];
                    count = 1;
                }

                i++;
            }

            // Add the last group
            next += to_string(count);
            next += prev;

            ans = next;

            index++;
        }

        return ans;
    }
};