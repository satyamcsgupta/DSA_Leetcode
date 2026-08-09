class Solution {
public:
    string reverseWords(string s) {

        // Step 1: Remove extra spaces
        string temp = "";
        int i = 0;
        int n = s.size();

        while (i < n) {

            // Skip leading spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            // Add one complete word
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            // Add only ONE space between words
            if (i < n) {
                temp += ' ';
            }
        }

        // Remove trailing space
        if (!temp.empty() && temp.back() == ' ') {
            temp.pop_back();
        }

        // Step 2: Reverse entire string
        reverse(temp.begin(), temp.end());

        // Step 3: Reverse every word
        int k = 0;

        for (int i = 0; i < temp.size(); i++) {

            if (temp[i] == ' ') {
                reverse(temp.begin() + k, temp.begin() + i);
                k = i + 1;
            }
        }

        // Last word
        reverse(temp.begin() + k, temp.end());

        return temp;
    }
};