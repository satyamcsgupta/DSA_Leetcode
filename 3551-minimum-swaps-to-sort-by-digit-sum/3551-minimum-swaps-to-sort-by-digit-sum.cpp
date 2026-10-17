class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while(x > 0) {
                sum += x % 10;
                x /= 10;
            }

            v.push_back({sum, nums[i]});
        }

        sort(v.begin(), v.end());

        unordered_map<int, int> pos;

        for(int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for(int i = 0; i < n; i++) {

            if(nums[i] != v[i].second) {

                int correctPos = pos[v[i].second];

                swap(nums[i], nums[correctPos]);

                pos[nums[correctPos]] = correctPos;
                pos[nums[i]] = i;

                swaps++;
            }
        }

        return swaps;
    }
};