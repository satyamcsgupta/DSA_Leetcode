class Solution {
public:
    int minAddToMakeValid(string s) {
     int  n=s.size();
     int count= 0;
     int left =0;
     for(int i =0;i<n;i++){
        if(s[i] ==  '('){
            count++;
        }else {
            count--;
            if(count <0){
                left++;
                count =0;
            }
        }
     }
     return left + count;
    }
};