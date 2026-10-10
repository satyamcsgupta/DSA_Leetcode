class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();

    
        vector<long long> freq(100001, 0);

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
        }

        long long k = (long long)k1 + k2;


        for (int d = 100000; d > 0 && k > 0; d--) {

            if (freq[d] == 0)
                continue;

    
    
            long long take = min(k, freq[d]);

            freq[d] -= take;
            freq[d - 1] += take;

            k -= take;
        }

       
        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};