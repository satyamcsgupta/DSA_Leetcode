class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // All even numbers except 2 are composite
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        for (int i = 3; i * i < n; i += 2) {

            if (isPrime[i]) {

                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 1; // count 2

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                ans++;
        }

        return ans;
    }
};