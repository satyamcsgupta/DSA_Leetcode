class Solution {
public:
    bool checkDivisibility(int n) {
        int temp =n;
        long long  sum = 0;
        long long  product =1;
        while(temp){
            int number =temp%10;
            temp = temp/10;
            sum += number;
            product =product*number;
            
        }
        return n % (sum + product) == 0;
    }
};