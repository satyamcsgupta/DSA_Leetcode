class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

        string res = "";
        int cycle = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++) {

            for (int j = i; j < s.size(); j += cycle) {

                res += s[j];

               
                int diagonal = j + cycle - 2 * i;

                if (i != 0 && i != numRows - 1 && diagonal < s.size()) {
                    res += s[diagonal];
                }
            }
        }

        return res;
    }
};