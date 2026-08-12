class Solution {
public:
    string frequencySort(string s) {

        map<int, int> count;

        // Count frequency
        for(int i = 0; i < s.size(); i++){
            count[s[i]]++;
        }

        // Move map elements into vector
        vector<pair<int,int>> arr;

        for(auto it : count){
            arr.push_back(it);
        }

        // Sort by frequency in decreasing order
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        // Build answer
        string ans = "";

        for(auto it : arr){
            while(it.second--){
                ans += char(it.first);
            }
        }

        return ans;
    }
};