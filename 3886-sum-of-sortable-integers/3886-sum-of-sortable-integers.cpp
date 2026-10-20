class Solution {
public:

    bool cheak_sort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();

        
        vector<int> divisor;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                divisor.push_back(i);
            }
        }

        long long sum = 0;

    
        if (cheak_sort(nums)) {
            for (int k : divisor) {
                sum += k;
            }

            return sum;
        }
        
        for (int k : divisor) {

            bool flag = true;

            int previousMax = -1;

        
            for (int i = 0; i < n; i += k) {

                int j = i + k - 1;

                int drops = 0;

                int mn = nums[i];
                int mx = nums[i];

                
                for (int p = i; p <= j; p++) {
                    mn = min(mn, nums[p]);
                    mx = max(mx, nums[p]);
                }

                
                for (int p = i; p <= j; p++) {

                    int next;

                    if (p == j)
                        next = i;
                    else
                        next = p + 1;

                    if (nums[p] > nums[next]) {
                        drops++;
                    }
                }


                
                if (drops > 1) {
                    flag = false;
                    break;
                }

                
                if (i != 0 && previousMax > mn) {
                    flag = false;
                    break;
                }

                previousMax = mx;
            }

            if (flag) {
                sum += k;
            }
        }

        return sum;
    }
};