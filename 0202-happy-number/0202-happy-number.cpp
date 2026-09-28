class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> visited;
        visited.insert(1);
        while (n != 1) {
            if (!visited.insert(n).second) {
                return false;
            }

            int sum = 0;
            while (n) {
                int mod = n % 10;
                sum += (mod * mod);
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};