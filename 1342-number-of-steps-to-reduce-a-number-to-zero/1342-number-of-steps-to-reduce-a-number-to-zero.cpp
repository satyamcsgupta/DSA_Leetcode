class Solution {
public:
    int numberOfSteps(int num) {
        int count =0;
        int n=num;
        while(n){
            if(n%2 ==0){
                n=n/2;
            }else{
                n--;
            }
            count++;
        }
        return count;
    }
};